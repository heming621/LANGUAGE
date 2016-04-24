#include <iostream>
using namespace std;
void Reverse(char*, char*);
int main()
{
    char* s1 = "abcdefg";
    char* s2 = s1;
    while(*(s2+1)!='\0')s2++;
    Reverse(s1, s2);
    while(*s1 != '\0')
	cout<<*s1<<"\t";
    return 0;
}

void Reverse(char* pBegin, char* pEnd)
{

    if(!pBegin || !pEnd || pEnd < pBegin)
	return;

    char tmp;
    while(pBegin != pEnd)
    {
	tmp = *pBegin;
	*pBegin = *pEnd;
	*pEnd = tmp;

	pBegin++;
	pEnd--;
    }
}
