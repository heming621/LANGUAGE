#! /usr/local/bin/python
#-- coding:utf-8 --
from __future__ import print_function
from collections import OrderedDict
import pprint
def CPUinfo():
    ''' Return the information in /proc/CPUinfo
\       as a dictionary in the following format:
        CPU_info['proc0']={...}
        CPU_info['proc1']={...}
    '''
    cpuinfo = OrderedDict()
    procinfo = OrderedDict()

    nprocs = 0
    #zi 将/proc/cpuinfo的值往procinfo送，逢空值，则计数一次cpuinfo的值
    with open('/proc/cpuinfo') as f:
        for line in f:
	    if not line.strip():
		cpuinfo['proc%s' % nprocs] = procinfo
		nprocs = nprocs+1
		#reset  zi将procinfo的值重新置为空
		procinfo = OrderedDict()
            else:
	        if len(line.split(':')) == 2:
		    procinfo[line.split(':')[0].strip()] = line.split(':')[1].strip()
		else:
		    procinfo[line.split(':')[0].strip()] = ''
    return cpuinfo

if __name__ == '__main__':
    cpuinfo = CPUinfo()
    for processor in cpuinfo.keys():
	#print(cpuinfo[processor]['model name'])
        print(cpuinfo[processor])
    #print(cpuinfo['model name'])

