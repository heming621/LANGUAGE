#! /usr/local/bin/python
#-*- coding:utf-8 -*-

''' Reference:http://blog.csdn.net/sunboy_2050/article/details/5969442'''

import sys
reload(sys)
sys.setdefaultencoding('utf-8')

import socket

class NetServer(object):
    def tcpServer(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)     #zi 只要SOCK_STREAM，后面一般bind(),listen(),accept()，再recv()返回接受到的数据；
        s.bind(('', 9527))  #绑定同一个域名下的所有机器
        s.listen(5)

        while True:
            clientSock, (remoteHost, remotePort) = s.accept()
            print("[%s:%s] connect "%(remoteHost, remotePort))       #接受客户端的ip, port

            recvData = clientSock.recv(1024)            #zi 如recv,后无括号，也没报错？
	    sendDataLen = clientSock.send("this is send data from server",(remoteHost, remotePort))
            print "recvData:", recvData
            print "sendDataLen:", sendDataLen

            clientSock.close()


if __name__ ==  "__main__":
    ns = NetServer()
    ns.tcpServer()
