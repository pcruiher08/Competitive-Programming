import json
import base64
from io import BytesIO
from PIL import Image
import requests
import boto3
import os
import numpy as np
import onnxruntime as ort 
from os import getenv

BUCKET_S3 = getenv('BUCKET_S3', '')

def load_onnx_model():
    s3_client = boto3.client('s3')
    bucket_name = BUCKET_S3
    model_file_key = 'models/yolov9c.onxx'
    local_model_path = '/tmp/yolov9c.onxx'


    if not os.path.exists(local_model_path):
        s3_client.download_file(bucket_name, model_file_key, local_model_path)


    ort_session = ort.InferenceSession(local_model_path)
    return ort_session


def process_image(event):
    body = json.loads(event['body'])

    img_url = body['url']

    response = requests.get(img_url)
    if response.status_code != 200:
        return {
            "statusCode": 400,
            "body": json.dumps({
                "error": "No se puede descargar la imagen."
            }),
        }

    img_b64 = response.content.decode('utf-8')

    img_data = base64.b64decode(img_b64)

    img = Image.open(BytesIO(img_data))

    # carga onnx
    ort_session = load_onnx_model()


    input_name = ort_session.get_inputs()[0].name
    input_shape = ort_session.get_inputs()[0].shape
    img = img.resize((input_shape[2], input_shape[1]))


    img_np = np.array(img) / 255.0  # Normalizar
    img_np = img_np.astype(np.float32)

    img_np = np.expand_dims(img_np, axis=0)

    ort_inputs = {input_name: img_np}
    ort_outputs = ort_session.run(None, ort_inputs)


    detections = ort_outputs[0]  

  
    response = {
        "statusCode": 200,
        "body": json.dumps({
            "detections": detections.tolist()  
        }),
    }
    return response


def lambda_handler(event, context):
    return process_image(event)
