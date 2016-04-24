#include <iostream>
extern "C"{
    #include <assert.h>
    #include <malloc.h>
}
using namespace std;
char* strcpy(char*, const char*);
void GetMemory1(char*);
void GetMemory2(char**);
void Test1(void);
void GetMemory3(char **p);
void Test2(void);
int main()
{

    char str1[10];
    char str2[] = "Hello";
    strcpy(str1,str2);
    cout<<str1<<endl;
    //02
    Test1();
    //03
    Test2();
    return 0;
}


//strcpy函数实现
char* strcpy(char* strDest, const char* strSour)
{
    assert(strDest!=NULL&&strSour!=NULL);
    char* address = strDest;
    while((*strDest++ = *strSour++)!='\0');
    return address;
}
//
void GetMemory1(char* p)    //wrong，应该传递二级指针，详见http://www.nowcoder.com/questionTerminal/7beda454b8a444428dfb6b13f9787e96
{
    p = (char*)malloc(100);
}
void GetMemory2(char **p)
{
    *p = (char*)malloc(100);
}
void Test1(void)
{
    //char str[] = "";
    char *str = NULL;
    GetMemory2(&str);
    strcpy(str,"hello world");
    cout<<str<<endl;
}
//
void GetMemory3(char **p, int num)
{
    *p = (char*)malloc(num);
    assert(*p!=NULL);
}
void Test2(void)
{
    char* str = NULL;
    GetMemory3(&str, 100);
    strcpy(str,"Hello3");
    cout << str << endl;
    if(str)
	free(str);
}
//




