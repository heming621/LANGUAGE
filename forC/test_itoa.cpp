#include <iostream>
extern "C"{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}
using namespace std;
int main()
{

    //Test03
    char s[100]="";
    cout<<"size_t的溢出："<<(unsigned int)(strlen(s)-1)<<endl;
    cout<<"int的最大值0x7FFFFFFF: "<<0x7FFFFFFF<<endl;
    cout<<"int的最小值0x80000000: "<<0x80000000<<endl;
    cout<<"int的最小值(signed)0x80000000: "<<(signed)0x80000000<<endl;
    cout<<"int的最小值(unsigned int)0x80000000: "<<(unsigned int)0x80000000<<endl;

    short int a = -1;
    int b = -1;
    cout<<"(signed int)(-1): "<<(signed int)(-1)<<endl;
    cout<<"(unsigned int)(-1): "<<(unsigned int)(-1)<<endl;
    cout<<"(signed int)(-1): "<<(short signed int)(-1)<<endl;
    cout<<"(unsigned int)(-1): "<<(short unsigned int)(-1)<<endl;

    cout<<"--"<<(unsigned int)0x80000000<<endl;

    //Test02
    cout<<(unsigned int)(-1)<<endl;
    cout<<(signed)0x80000000<<endl;
    cout<<(signed int)0x80000000<<endl;
    cout<<0x80000000<<endl;
    cout<<011<<endl;
    if((-1)<(signed int)0x80000000)
	cout<<"YES"<<endl;
    else if((-1)>(signed int)0x80000000)
	cout<<"NO"<<endl;
    else
	cout<<"EEEE"<<endl;

    //Test01
    int num = 100;
    char str[25];
    sprintf(str,"%d",num);
    cout<<str<<endl;
    //itoa(num, str, 10);
    //printf("%s",str);
    return 0;
}
