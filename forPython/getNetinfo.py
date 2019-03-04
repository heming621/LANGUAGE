#! /usr/local/bin/python
#coding=utf8
import time
import sys

if len(sys.argv) > 1:
    INTERFACE = sys.argv[1]
else:
    INTERFACE = 'eth0'

STATS = []
print 'Interface:',INTERFACE

def rx():
    ifstat = open('/proc/net/dev').readlines()
    for val in ifstat:
	if INTERFACE in val:
	    stat = float(val.split()[1])
	    STATS[0:] = [stat]

def tx():
    ifstat = open('/proc/net/dev').readlines()
    for val in ifstat:
	if INTERFACE in val:
	    stat = float(val.split()[9])
	    STATS[1:] = [stat]

print 'In	Out'
rx()
tx()

while True:
    time.sleep(1)
    rxstat_o = list(STATS)
    rx()
    tx()
    RX = float(STATS[0])  # 全局变量STATS，存储
    RX_0 = rxstat_o[0]
    TX = float(STATS[1])
    TX_0 = rxstat_o[1]
    RX_RATE = round((RX - RX_0)/1024/1024, 3)
    TX_RATE = round((TX - TX_0)/1024/1024, 3)
    print RX_RATE, 'MB	', TX_RATE, 'MB'










