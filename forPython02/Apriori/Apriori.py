#!/usr/bin/env python
#encoding=utf8

import sys
import os
import pickle
import socket
import signal
from optparse import OptionParser

# 中文帮助编码问题修复
reload(sys)
sys.setdefaultencoding('utf-8')

# 并行管理
ChildProcess = 0
ParentSocket = None
ChildSocket = None

SrcDataFile = None

SrcPropertyFile = None

MinSup = 0.0

MinConf = 0.0

MinLen = 0.0

N = 0

Items = []

Transaction = []

FrequentItemResult = []

F = []
FCount = {}

Rule = []

class Candidate:
    def __init__(self, k):
        # 候选项长度
        self.length = k
        self.candidate = []
        self.support = []

    def addCandidate(self, candidate):
        if candidate in self.candidate:
            print '已是候选项成员'
        else:
            self.candidate.append(candidate)
            self.support.append(0)

    def addAll(self, candidatesets):
        self.candidate = candidatesets
        length = len(self.candidate)
        for i in range(length):
            self.support.append(0)

    # 计算候选项支持度
    def incSupport(self, candidate = None, index = None):
        if index != None:
            self.support[index] = self.support[index] + 1
        elif candidate != None:
            if candidate in self.candidate:
                try:
                    index = self.candidate.index(candidate)
                    self.support[index] = self.support[index] + 1
                except:
                    print '候选项索引错误'
            else:
                print '候选项错误'
                self.candidate.append(candidate)
                self.support.append(1)
        else:
            print '参数缺失'

    # 释放频繁K项集
    def extractFrequentSet(self):
        global N
        global MinSup
        returnSet = []
        returnCount = []
        for i,items in enumerate(self.candidate):
            if self.support[i] >= int(N * MinSup):
                returnSet.append(items)
                returnCount.append(self.support[i])

        return returnSet, returnCount

    # 返回候选项个数
    def getNumOfCandidate(self):
        return len(self.candidate)

    # 返回特定候选项
    def getOneCandidate(self, index):
        return self.candidate[index]

    # 返回全部候选项
    def getAllCandidate(self) :
        return self.candidate

    # 返回全部候选项支持度
    def getAllNumber(self):
        return self.support

# 哈希树，哈希公式：h(p) = p mod 3
class HashTree:
    def __init__(self, items, lenItem, level):
        self.length = lenItem
        self.items = items
        self.leftChild = None
        self.midChild = None
        self.rightChild = None
        self.makeUpTree(level)

    def makeUpTree(self, level):
        # 递归终止条件
        if level == self.length - 1:
            tempbucket = []
            for subitem in self.items:
                prefixItem = subitem[:level]
                sufixItem = subitem[level:]
                for sitem in sufixItem:
                    tempbucket.append(prefixItem + [sitem])
            self.items = tempbucket

        else:
            leftItems = []
            midItems = []
            rightItems = []

            for subitem in self.items:
                # 可用前缀数
                numPre = len(subitem) - self.length + 1
                for index in range(level, level+numPre):
                    # 获取子项，如: abcd->abcd, bcd, cd
                    tempItem = subitem[:level] + subitem[index:]
                    hashValue = int(subitem[index]) % 3
                    if hashValue == 0:
                        leftItems.append(tempItem)
                    elif hashValue == 1:
                        midItems.append(tempItem)
                    else:
                        rightItems.append(tempItem)

            if len(leftItems) != 0:
                self.leftChild = HashTree(leftItems, self.length, level + 1)
            if len(midItems) != 0:
                self.midChild = HashTree(midItems, self.length, level + 1)
            if len(rightItems) != 0:
                self.rightChild = HashTree(rightItems, self.length, level + 1)

    # 判断候选项是否在事务中
    def identifyCandidate(self, candidate, level):
        # 终止条件
        if self.length == level + 1:
            if candidate in self.items:
                return True
            else:
                return False
        else:
            hashvalue = int(candidate[level]) % 3
            if hashvalue == 0:
                if self.leftChild == None:
                    return False
                return self.leftChild.identifyCandidate(candidate, level + 1)
            elif hashvalue == 1:
                if self.midChild == None:
                    return False
                return self.midChild.identifyCandidate(candidate, level + 1)
            else:
                if self.rightChild == None:
                    return False
                return self.rightChild.identifyCandidate(candidate, level + 1)

def GetItems(fd):
    alldata = fd.read()

    for data in alldata.split('\n'):
        if data != '':
            Items.append(data)

def GetTrans(fd):
    global N
    global Items
    global Transaction

    alldata = fd.read()
    for dataline in alldata.split('\n'):
        if dataline != '':
            N = N + 1
            tempset = []
            index = 0
            for i, data in enumerate(dataline.split(',')):
                if i == 0:
                    if data == Items[0]:
                        tempset.append(str(0))
                    elif data == Items[1]:
                        tempset.append(str(1))
                else:
                    if data == 'y':
                        tempset.append(str(index))
                    elif data == 'n':
                        tempset.append(str(index+1))
                    else:
                        pass
                index = index + 2
            tempset.sort(key = int)
            Transaction.append(tempset)

def aprioriGen(itemsets, length):
    '''
    使用 F(k-1)XF(k-1) 方法
    '''
    candidateset = []
    numItem = len(itemsets)
    for i in range(numItem-1):
        for j in range(i+1, numItem):
            if itemsets[i][:-1] == itemsets[j][:-1] and itemsets[i][-1] != itemsets[j][-1] and (int(itemsets[i][-1]) / 2) != (int(itemsets[j][-1]) / 2):                                                                                                    ###||itemsets[i][-1:] get the list, and the list can't be converted into integer
                tempCandidate = itemsets[i][:-1]
                tempCandidate.append(itemsets[i][-1])
                tempCandidate.append(itemsets[j][-1])
                tempCandidate.sort(key = int)
                # 修枝
                for k in range(length-1):
                    tempPrun = tempCandidate[:k]+tempCandidate[k+1:]
                    # 符合修枝条件
                    if tempPrun not in itemsets:
                        tempCandidate = None
                        break
                if tempCandidate != None:
                    candidateset.append(tempCandidate)
    return candidateset

def subset(candidateSet, root):
    numCandidate = candidateSet.getNumOfCandidate()
    for index in range(numCandidate):
        level = 0
        if root.identifyCandidate(candidateSet.getOneCandidate(index), level):
            candidateSet.incSupport(None, index)

def conToKey(items):
    key = ''
    for item in items:
        key = key + item + '_'
    return key

def apGenRules(fk, hm):
    lenItem = len(fk)
    lenSufixRule = len(hm[0])

    if lenItem > lenSufixRule + 1:
        # P216，规则产生
        hm1 = aprioriGen(hm, lenSufixRule)
        # 存储修正项
        Hm1 = []
        for sufixRule in hm1:
            prefixRule = list(set(fk) - set(sufixRule))
            prefixRule.sort(key = int)
            conf = float(FCount[conToKey(fk)]) / FCount[conToKey(prefixRule)]
            if conf >= MinConf:
                Rule.append([sufixRule, prefixRule, conf])
                Hm1.append(sufixRule)
        if len(Hm1) != 0:
            apGenRules(fk, Hm1)

def showFrequentSets():
    print F
    pass


def showRules():
    global Rule
    global Items

    for rule in Rule:
        mark = False
        prefixLine = '{'
        numItem = len(rule[1])
        for i, index in enumerate(rule[1]):
            if i == numItem - 1:
                prefixLine = prefixLine + Items[int(index)] + '}'
            else:
                prefixLine = prefixLine + Items[int(index)] + ','
        midLine = '-->'
        sufixLine = '{'
        numItem = len(rule[0])
        if len(rule[0]) == 1:
            for i, index in enumerate(rule[0]):
                if (int(index) == 1 or int(index) == 0):
                    mark = True
                if i == numItem - 1:
                    sufixLine = sufixLine + Items[int(index)] + '}'
                else:
                    sufixLine = sufixLine + Items[int(index)] + ','
            if (mark == True):
                print prefixLine + midLine + sufixLine + '   置信度: ' + str(rule[2])

def termSigHandle(signum, frame):
    if ParentSocket:
        os.unlink("/tmp/apriori-parent")
    if ChildSocket:
        os.unlink("/tmp/apriori-child")

if __name__ =='__main__':

    # 退出事件捕捉
    signal.signal(signal.SIGTERM, termSigHandle)
    signal.signal(signal.SIGINT, termSigHandle)

    # 参数解析器
    optparser = OptionParser()
    optparser.add_option('-f', '--inputDataSource',
                         dest='inputDataSource',
                         default=None,
                         help='数据源')
    optparser.add_option('-i', '--inputProperty',
                         dest='inputProperty',
                         default=None,
                         help='数据属性')
    optparser.add_option('-s', '--minSupport',
                         dest='minS',
                         help='最小支持度',
                         default=0.30,
                         type='float')
    optparser.add_option('-c', '--minConfidence',
                         dest='minC',
                         help='最小置信度',
                         default=0.90,
                         type='float')

    optparser.add_option('-l', '--minLen',
                         dest='minL',
                         help='最小规则长度',
                         default=4,
                         type='int')

    (options, args) = optparser.parse_args()

    if options.inputDataSource is not None:
        SrcDataFile = options.inputDataSource
    else:
        print '没有指定数据源'
        sys.exit()

    if options.inputProperty is not None:
        SrcPropertyFile = options.inputProperty
    else:
        print '没有指定属性'
        sys.exit()

    MinSup = options.minS
    MinConf = options.minC
    MinLen = options.minL

    fd = open(SrcPropertyFile, 'r')
    # 从文件中获取数据源“属性”
    GetItems(fd)
    fd.close()
    # zhm
    # print Items
    # zhm

    fd = open(SrcDataFile, 'r')
    # 从文件中获取数据
    GetTrans(fd)
    fd.close()
    # zhm    
    # print Transaction 
    # zhm
     
    # 频繁项集初始长度
    lenItem = 1
    # 频繁集初始化
    candidateSet = Candidate(lenItem)
    for i in range(len(Items)):
        candidateSet.addCandidate([str(i)])
    
    '''
    # 对1-频繁集计算支持度
    numOfCandidate = candidateSet.getNumOfCandidate()
    for transaction in Transaction:
        for index in range(numOfCandidate):
            candidate = candidateSet.getOneCandidate(index)
            if candidate[0] in transaction:
                candidateSet.incSupport(None, index)
    # 释放频繁项，获取1-项集
    candidatesets, setscount = candidateSet.extractFrequentSet()

    F.append(candidatesets)
    for i, item in enumerate(candidatesets):
        FCount[conToKey(item)] = setscount[i]


    # 创建子进程
    ChildProcess = os.fork()

    if ChildProcess:
        ParentSocket = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
        ParentSocket.bind("/tmp/apriori-parent")
        ParentSocket.recv(1024)
    else:
        ChildSocket = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
        ChildSocket.bind("/tmp/apriori-child")
        ChildSocket.sendto("Go", "/tmp/apriori-parent")

    # 切分数据
    if ChildProcess == 0:
        Transaction = Transaction[:len(Transaction)/2]
    else:
        Transaction = Transaction[len(Transaction)/2:]

    # TODO: unix domain socket收发逻辑
    while True:
        lenItem = lenItem + 1
        if ChildProcess:
            candidateSet = Candidate(lenItem)
            # 将项目集添加到候选集
            candidateSet.addAll(aprioriGen(F[lenItem-2], lenItem-1))
            # 序列化对象发送给子进程
            candidateDumps = pickle.dumps(candidateSet)
            ParentSocket.sendto(candidateDumps, "/tmp/apriori-child")

        if ChildProcess == 0:
            candidateDumps = ChildSocket.recv(204800)
            candidateSet = pickle.loads(candidateDumps)

        # 生成 Hash Tree
        for transaction in Transaction:
            templist = []
            templist.append(transaction)
            # 树深
            level = 0
            root = HashTree(templist, lenItem, level)
            subset(candidateSet, root)

        if ChildProcess == 0:
            candidateDumps = pickle.dumps(candidateSet)
            ChildSocket.sendto(candidateDumps, "/tmp/apriori-parent")


        if ChildProcess:
            candidateDumps = ParentSocket.recv(204800)
            candidateSetChild = pickle.loads(candidateDumps)

            # 合并父子进程数据
            for item in candidateSetChild.candidate:
                if item in candidateSet.candidate:
                    candidateSet.support[candidateSet.candidate.index(item)] += candidateSetChild.support[candidateSetChild.candidate.index(item)]
                else:
                    candidateSet.candidate.append(item)
                    candidateSet.support.append(candidateSetChild.support[candidateSetChild.candidate.index(item)])


            candidatesets, setscount = candidateSet.extractFrequentSet()
            if len(candidatesets) == 0:
                break
            F.append(candidatesets)
            for i, item in enumerate(candidatesets):
                FCount[conToKey(item)] = setscount[i]

            if lenItem == MinLen:
                break

    print "生成规则..."

    # 不同项目类别长度
    kindsItem = len(F)
    print kindsItem
    for k in range(MinLen - 1, MinLen):
        for frequentItem in F[k]:
            F1 = []
            for subItem in frequentItem:
                sufixRule = [subItem]
                prefixRule = list(set(frequentItem) - set(sufixRule))
                prefixRule.sort(key = int)
                conf = float(FCount[conToKey(frequentItem)]) / FCount[conToKey(list(prefixRule))]
                if conf >= MinConf:
                    Rule.append([sufixRule, prefixRule, conf])
                    F1.append(sufixRule)
            # 生成规则
            if len(F1) > 0:
                apGenRules(frequentItem, F1)

    showRules()

    os.unlink("/tmp/apriori-parent")
    os.unlink("/tmp/apriori-child")
    ''' ''' '''
