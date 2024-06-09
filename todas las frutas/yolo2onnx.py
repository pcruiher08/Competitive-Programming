from ultralytics import YOLO 
import torch
from collections.abc import Mapping

model = YOLO("yolov9c.pt")

#path = model.export(format == "onnx")