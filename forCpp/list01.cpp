#include <iostream>
using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
}

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();   //用new，新建节点，作为插入的节点
    PNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if(*pHead == NULL)    //若空链表，则新增节点为头节点
    {
	*pHead = pNew;
    }
    else
    {
	ListNode* pNode = *pHead;
	while(pNode->m_pNext != NULL)
	    pNode = pNode->m_pNext;

	pNode->m_pNext = pNew;
    }

}


int main()
{

    return 0;
}
