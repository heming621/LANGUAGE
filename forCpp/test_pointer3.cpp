#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a1 = 2686748;
    int a2 = 0x28ff1c;
    int a4= 012347434;
    int *p = (int*)10;
    cout<<p<<endl;       //output "0xa", I got this.
    char *pc = (char*)'A';
    //cout<<*pc<<endl;   // Segmentation fault. Why?
    //cout<<pc<<endl;    // Segmentation fault. Why?
    //cout<<&pc<<endl;   // output "0x7fffffffeb90",
    char *pt = (char*)"abc";
    cout<<*pt<<endl;     // output "a"
    cout<<pt<<endl;      // output "abc"
    cout<<&pt<<endl;     // output "0x7fff13463888"

    
    //from 牛客网
    int a[ 5 ] = {2,4,6,8,10}, *p1, **k;
    p1 = a; 
    k = &p1;
    cout<< *(p1++) <<endl;  //output 2
    cout<< **k <<endl;     //output 4
    
    
    
    return 0;
}
