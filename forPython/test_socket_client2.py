''' Reference:http://blog.csdn.net/sunboy_2050/article/details/5969442'''
#! /usr/local/bin/python
#-*- coding:utf-8 -*-

import sys
reload(sys)
sys.setdefaultencoding('utf-8')

import socket

class NetClient(object):
    def tcpClient(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect(('localhost', 9527))
	
	sendDataLen = s.send("this is send data from client") #zi 往connect()中的ip,port发送数据
	recvData = s.recv(1024)
        print "sendDataLen:", sendDataLen
	print "recvData:", recvData

	s.close()

if __name__ == "__main__":
    nc = NetClient()
    nc.tcpClient()
