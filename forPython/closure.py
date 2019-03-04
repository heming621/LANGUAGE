#-*- coding:utf8 -*-
import os
def addx(x):
    def adder(y):return x+y
    return adder

add8 = addx(8)
add9 = addx(9)
add10 = addx(10)  # 定义函数add10，

print add8(100)
print add9(100)
print add10(100)
