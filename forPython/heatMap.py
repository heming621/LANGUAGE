#! /usr/local/bin/python
#-*- coding=utf-8 -*-
import urllib
from pyheatmap.heatmap import HeatMap

def main():
    #下载测试数据 #zi 测试数据是一行一行的"x, y"形式
    url = "https://raw.github.com/oldj/pyheatmap/master/examples/test_data.txt"
    sdata = urllib.urlopen(url).read().split("\n")
    data = []
    for ln in sdata:
        a = ln.split(",")
	if(len(a)!=2):
	    continue
	a = [int(i) for i in a]  # a = [lambda int(i):i for i in a]
	data.append(a)   #zi data装载int类型的元素

    #开始绘制
    hm = HeatMap(data)
    hm.clickmap(save_as="hit.png")
    hm.heatmap(save_as="heat.png")

if __name__ == "__main__":
    main()
