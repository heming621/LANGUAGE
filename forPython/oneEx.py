# -*- coding:utf-8 -*-
# Quick Python Script Explanation for Programmers
# 
import os
def main():
    print 'Hello World'
    
    print 'This is Alice\'s hello!'
    print "This is Bob\'s hello!"

    foo(5, 10)
    
    print '='*10
    print 'This will directly execute'+os.getcwd()

    counter = 0
    counter +=1

    food=['apple','dfa','lizi','li']
    for i in food:
        print 'I like:'+i
    
    print 'Count 10...'
    for i in range(10):
        print i


def foo(param1, secondParam):
    res = param1+secondParam
    print '%s + %s = %s'%(param1, secondParam, res)
    if res<50:
        print '<50'
    elif(res>=50)and((param==42)or(secondParam==24)):
        print '>=50 42 24'
    else:
        print '>50'
    return res


if __name__=='__main__':
    main()
