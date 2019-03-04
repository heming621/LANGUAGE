#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    char *pc = (char*)"A";
    cout<<*pc<<endl;
    cout<<pc<<endl;
    printf("%x\n",pc);
    
    int *pi = (int*)99999;
    cout<<*pi<<endl;
    cout<<pi<<endl;
    return 0;
}
