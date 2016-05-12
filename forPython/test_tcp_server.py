#! /usr/local/bin/python
#-*- coding:utf-8 -*-

''' Reference:http://blog.csdn.net/sunboy_2050/article/details/5969442'''

import sys
reload(sys)
sys.setdefaultencoding('utf-8')

import socket

class NetServer(object):
    def tcpServer(self):
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.bind(('', 9527))  #绑定同一个域名下的所有机器
