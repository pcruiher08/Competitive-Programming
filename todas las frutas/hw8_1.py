import numpy as np
import keras
import keras.utils
from keras import backend as K
from keras.models import Sequential
from keras.layers import Activation, Dense, Flatten
from keras.layers.core import Dense
from keras.optimizers import Adam
from keras.metrics import categorical_crossentropy
from keras.preprocessing.image import ImageDataGenerator
from keras.layers.normalization import BatchNormalization
from keras.layers.convolutional import *
from matplotlib import pyplot as plt    
from sklearn.metrics import confusion_matrix
import itertools
import matplotlib.pyplot as plt
import matplotlib

trainingPath = 'cats_and_dogs/train'
validPath = 'cats_and_dogs/valid'
testPath = 'cats_and_dogs/test'

trainingBatches = ImageDataGenerator().flow_from_directory(trainingPath, target_size=(224,224),classes=['dog','cat'], batch_size=10)
validBatches = ImageDataGenerator().flow_from_directory(validPath, target_size=(224,224),classes=['dog','cat'], batch_size=4)
testBatches = ImageDataGenerator().flow_from_directory(testPath, target_size=(224,224),classes=['dog','cat'], batch_size=10)

imgs, labels= next(trainingBatches)
model=Sequential([Conv2D(32, (3, 3), activation = 'relu', input_shape=(224,224, 3)),Flatten(),Dense(2, activation='softmax'),])
model.compile(Adam(lr=.0001),loss='categorical_crossentropy', metrics=['accuracy'])
model.fit_generator(trainingBatches, steps_per_epoch=4,validation_data=validBatches, validation_steps=4, epochs=5, verbose=2)
imagenes, testLibraries= next(testBatches)
testLibraries=testLibraries[:,0]
predictions= model.predict_generator(testBatches, steps=1, verbose=0)
vgg16_model= keras.applications.vgg16.VGG16()
vgg16_model.summary()
model=Sequential()

for layer in vgg16_model.layers:
    model.add(layer)
    
model.summary()
model.layers.pop()
model.summary()

for layer in model.layers:
    layer.trainable= False

model.add(Dense(2, activation="softmax"))
model.summary()

model.compile(Adam(lr=.0001), loss= 'categorical_crossentropy', metrics=['accuracy'])
model.fit_generator(trainingBatches, steps_per_epoch=4, validation_data=validBatches, validation_steps=4, epochs=5, verbose=2)