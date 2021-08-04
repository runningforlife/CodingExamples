#!/usr/bin/python

import os
import pandas as pd
from mxnet import np

def make_data_file():
    os.makedirs(os.path.join('..', 'data'), exist_ok=True)
    data_file = os.path.join('..', 'data', 'tiny_hourse.csv')

    with open(data_file, 'w') as f:
        f.write('NumRooms, Alley, Price\n')
        f.write('NA, Pave, 127500\n')
        f.write('2, NA, 106000\n')
        f.write('4, NA, 178100\n')
        f.write('NA, NA, 140000\n')

    return data_file

def load_data(data_file):
    data = pd.read_csv(data_file)
    print(data)

    inputs, outputs = data.iloc[:, 0:2], data.iloc[:, 2]
    inputs = inputs.fillna(inputs.mean())
    print(inputs)

    inputs = pd.get_dummies(inputs, dummy_na=True)
    print(inputs)

    X, y = np.array(inputs.values), np.array(outputs.values)

    print(X)
    print(y)

if __name__ == "__main__":
    load_data(make_data_file())

