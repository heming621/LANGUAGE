#-*- coding=utf-8 -*-
import os
#将n个数填进列表
def listGen(n):
    list=[]
    for i in range(1,n+1):
	list.append(i)
    return list

#将list中与rp相同的元素删掉
def delRe(rp,list):
    listTmp=[]
    for val in list:
        if val != rp:
            listTmp.append[val]
    return listTmp

#list1的第一个元素为i，后面的元素是list1的元素，按list2的序数（list2可以称为序数列表）
def form(i,list1,list2):
    listTmp=[]
    listTmp.append(i)
    count=0
    for i in list2:
        count+=1;
	listTmp.insert(count,list1[i-1])  #insert方法，将list1[i-1]元素插入到索引号为count的位置
    return listTmp

    
def fun(n):
    if n==2:
        return [[1,2],[2,1]]
    else:
        back=[]
        list1 = listGen(n)
        for val in list1:
            list2 = delRe(val, list1)  #将list1中val元素去除，即去掉list1中的重复元素
            for val in fun(n-1):       #按val序数，将i和list2合并赋给list3
		list3=form(i,list2,val)
		back.append(list3)
	return back

		   
		   
list = fun(5)
count = 1
for val in list:
    print str(count)+':'+str(val)   #str方法，将数值变为字符串
    count+=1




