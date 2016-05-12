#! /usr/local/bin/python
#-*- coding=utf8 --*-
import os
import signal
import time

def signal_user1(signum, frame):
    pid = os.getpid()
    print('Recevied USR1 in process %s' % pid)

print('Forking...')
child_pid = os.fork()

#执行父进程代码，
#“两个进程的唯一区别是fork的返回值。子进程接收返回值0，而父进程接收子进程的pid作为返回值。...子进程中返回0值而父进程中返回子进程ID”    
if child_pid:
    print('Parent:pausing before sending signal。。。')
    time.sleep(1)
    print('Parent:signaling %s'%child_pid)
    os.kill(child_pid, signal.SIGUSR1)

else:
    print('Child:setting up signal handler')
    signal.signal(signal.SIGUSR1, signal_user1)  #zi 执行上面signal_user1定义的内容
    print('Child:pausing to wait for signal')
    time.sleep(5)
