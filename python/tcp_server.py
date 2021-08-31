#!/usr/bin/python
"""

a tcp server accepting connections from multiple clients
and send clients current system time

"""

import socket
from datetime import datetime
import argparse
from multiprocessing.dummy import Pool
from concurrent.futures import ThreadPoolExecutor
import os

class TcpServer:

    def __init__(self, port):
        self.port = port
        self.backlog = 6
        #self.pool = Pool(os.cpu_count())
        self.threads = os.cpu_count()
        print(f'number of threads: {os.cpu_count()}')

    def start_server(self):
        """start a tcp server on given port"""
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        # bind socket to localhost
        print('public host name:' + socket.gethostname())
        sock.bind(('localhost', self.port))
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEPORT, 1)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        sock.listen(self.backlog)
        while True:
            client_sock, addr = sock.accept()
            print('accepting request from ' + str(addr))

            with ThreadPoolExecutor(max_workers=self.threads) as executor:
                executor.submit(self.process_request, client_sock)
            #self.pool.apply_async(self.process_request, (client_sock, ))
            #self.process_request(client_sock)

    def process_request(self, client_sock):
        """process request from client"""
        print(f'pid: {os.getpid()}')
        client_sock.send(str(datetime.now()).encode('utf-8'))

def parse_args():
    parser = argparse.ArgumentParser(description='start a tcp server')
    parser.add_argument('-p', type=int, metavar='tcp port', help='tcp server port', required=True)
    return parser.parse_args()

def main():
    args = parse_args()

    server_port = args.p
    print('tcp port ' + str(server_port))

    tcp_server = TcpServer(server_port)
    tcp_server.start_server()


if __name__ == '__main__':
    main()
