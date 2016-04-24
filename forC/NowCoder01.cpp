#include <iostream>
#include <string>
extern "C" {
    #include <string.h>
    #include <stdio.h>
}
using namespace std;
char* getMemory04(void);
void test04(void);
void test05();
int main()
{
    //牛客网某题1
    int c1 = 2<<2>>2;
    int c2 = 2>>2<<2;
    cout<<(2<<2)<<endl;             //output 8; cout<<2<<2<<endl; output 22
    cout<<(2<<2>>2)<<endl;          //output 2; 移位运算符满足左结合律，(2<<2)>>2，0010--1000--0010
    cout<<(2>>2)<<endl;             //output 0; 
    cout<<(2>>2<<2)<<endl;          //output 0;
    
    //牛客网某题2  //考察strcpy、strcmp
    char ccString1[] = "Is Page Fault??";
    char ccString2[] = "No Page Fault??";
    strcpy(ccString1, "No");         //将ccString1全覆盖为"No"；
    cout<<ccString1<<endl;           //cout<<strlen(ccString1)<<endl;
    cout<<ccString2<<endl; 
  
    //牛客网某题3  //字符串赋值有'\0'; strlen()不计'\0';
    char a[] = "ABCDEF";
    char b[] = {'A','B','C','D','E','F'};
    cout << strlen(a) << endl;     //6
    cout << strlen(b) << endl;     //6
    cout << sizeof(a) << endl;     //7
    cout << sizeof(b) << endl;     //6
    char c[] = {'A','B','C','D','E','F','\0'};  
    cout << sizeof(a) << " " << sizeof(c) << endl;

    //
    test04();
    //
    test05();
    return 0;
}

//牛客网某题4
char* getMemory04(void)
{
    char p[] = "hello world";
    return p;
}
void test04(void)
{
    char *str = NULL;
    str = getMemory04();
    cout<<str<<endl;
}

//牛客网某题5
void test05()
{
    char a[10] = "abc", b[10] = "012", c[10] = "xyz";
    strcpy(a+1, b+2);
    cout<<a<<endl;
    puts(strcat(a,c+1));
}


