#! /usr/local/bin/python
import socket

'''Reference:http://blog.csdn.net/sunboy_2050/article/details/5969442 '''
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(('127.0.0.1', 31511))

while True:
    data, addr = s.recvfrom(2048)
    if not data:
        print "client has exit"
	break
    print "recevied:", data, " from ", addr

s.close()
