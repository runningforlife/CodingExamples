# simple examples of linear regression
import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt
from d2l import tensorflow as d2l

#get data set
w_init = tf.constant([2, -3.4])
b_init = 4.0

features, labels = d2l.synthetic_data(w_init, b_init, 1000)

#read data set(training set/test set)
def load_array(data_arr, batch_size, is_train=True):
    dataset = tf.data.Dataset.from_tensor_slices(data_arr)
    if is_train:
            dataset = dataset.shuffle(buffer_size=1000)
    dataset = dataset.batch(batch_size)

    return dataset

#plt.plot(features, labels, '*')
#plt.show()

batch_size = 10

data_iter = load_array((features, labels), batch_size)

#print(next(iter(data_iter)))

#define model, initialize model params
initializer = tf.initializers.RandomNormal(stddev=0.01) 
net = tf.keras.Sequential(layers=None, name="lg")
net.add(tf.keras.layers.Dense(1, kernel_initializer=initializer))

#define loss function
loss = tf.keras.losses.MeanSquaredError()
#define opt algorithm
trainer = tf.keras.optimizers.SGD(learning_rate=0.03)

#starting training
num_epochs = 3
for epoch in range(num_epochs):
    for X, y in data_iter:
        with tf.GradientTape() as tape:
            l = loss(net(X, training=True), y)
            grads = tape.gradient(l, net.trainable_variables)
            trainer.apply_gradients(zip(grads, net.trainable_variables))
    l = loss(net(features), labels)
    print(f'epoch {epoch + 1}, loss {l:f}')



