import numpy as np
from random import randint
from sklearn.preprocessing import MinMaxScaler
import keras
from keras import backend as K
from keras.models import Sequential
from keras.layers import Activation
from keras.layers.core import Dense
from keras.optimizers import Adam
from keras.metrics import categorical_crossentropy
from sklearn.metrics import confusion_matrix
import itertools
import matplotlib.pyplot as plt
from keras.models import load_model
from keras.models import model_from_json

train_labels = []
train_samples = []

for i in range(50):
    random_younger = randint(13,64)
    train_samples.append(random_younger)
    train_labels.append(1)
    random_older = randint(65,100)
    train_samples.append(random_older)
    train_labels.append(0)
    
for i in range(1000):
    random_younger = randint(13,64)
    train_samples.append(random_younger)
    train_labels.append(0)
    
    random_older = randint(65,100)
    train_samples.append(random_older)
    train_labels.append(1)

for raw in train_samples:
    print(raw)

train_labels = np.array(train_labels)
train_samples = np.array(train_samples)

scaler = MinMaxScaler(feature_range=(0,1))
scaled_train_samples = scaler.fit_transform((train_samples).reshape(-1,1))

for i in scaled_train_samples:
    print(i)

model = Sequential([Dense(16, input_shape=(1,), activation='relu'),Dense(32, activation='relu'),Dense(2, activation='softmax')])

model.summary()
model.compile(Adam(lr=.0001), loss='sparse_categorical_crossentropy', metrics=['accuracy'])
model.fit(scaled_train_samples, train_labels, validation_split = 0.1, batch_size=10, epochs=20, shuffle=True, verbose=2)

test_labels = []
test_samples = []

for i in range(10):
    random_younger = randint(13,64)
    test_samples.append(random_younger)
    test_labels.append(1)
    random_older = randint(65,100)
    test_samples.append(random_older)
    test_labels.append(0)
    
for i in range(200):
    random_younger = randint(13,64)
    test_samples.append(random_younger)
    test_labels.append(0)
    random_older = randint(65,100)
    test_samples.append(random_older)
    test_labels.append(1)

test_labels = np.array(test_labels)
test_samples = np.array(test_samples)

scaler = MinMaxScaler(feature_range = (0,1))
scaled_test_samples = scaler.fit_transform((test_samples).reshape(-1,1))

predictions = model.predict(scaled_test_samples, batch_size=10, verbose = 0)

for pred in predictions:
    print(pred)

rounded_predictions = model.predict_classes(scaled_test_samples, batch_size=10, verbose=0)

for pred in rounded_predictions:
    print(pred)

cm = confusion_matrix(test_labels, rounded_predictions)
cm_plot_labels = ['no_side_effects','had_side_effects']
model.save('medical_trial_model.h5')
new_model = load_model('medical_trial_model.h5')
new_model.summary()
new_model.get_weights()
new_model.optimizer
json_string = model.to_json()
json_string
model_architecture = model_from_json(json_string)
model_architecture.summary()
model.save_weights('my_model_weights.h5')
model2  = Sequential([
    Dense(16, input_shape=(1,), activation='relu'),
    Dense(32, activation='relu'),
    Dense(2, activation='softmax')
])

model2.load_weights('my_model_weights.h5')
