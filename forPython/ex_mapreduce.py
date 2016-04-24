#-*- coding=utf-8 -*-
import os
### about map() ###
def power(x):
    return x*x

print map(power, [1,2,3,4,5,6,7,8,9])
print map(str, [1,2,3,4,5,6,7,8,9])

### about reduce ###
def add(x,y):
    return x+y
def fn(x,y):
    return x*10+y

print reduce(add, [1,3,5,7,9]) #output 25
print reduce(fn,[1,3,5,7,9]) #ouput 13579


def str2int(s):
    def fn(x,y):
        return x*10+y
    def char2num(s):
        return {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}[s]
    return reduce(fn,map(char2num,s))

print str2int('13579')
