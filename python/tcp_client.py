#!/usr/bin/python

"""
a tcp client to send request to server
"""

import socket
import argparse


def recv_data(sock):
    buf = sock.recv(2048)
    print('recieved from server:' + buf.decode('utf-8'))

def start_client(id, port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(('localhost', port))
    print(f'start client {id}')
    recv_data(sock)
    sock.close()

def parse_args():
    parser = argparse.ArgumentParser('start multiple tcp client')
    parser.add_argument('-n', type=int, metavar='clients number', default=1, help='number of clients to start')
    parser.add_argument('-p', type=int, metavar='tcp port', required=True, help='tcp port to connect')

    return parser.parse_args()

def main():

    args = parse_args()
    clients = args.n
    port = args.p

    print(f'the number of clients:{clients}, tcp port:{port}')
    for i in range(clients):
        start_client(i, port)

if __name__ == '__main__':
    main()
