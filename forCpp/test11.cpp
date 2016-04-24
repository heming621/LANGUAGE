#include <iostream>
using namespace std;
void reset(int *ip);
void reset2(int &p);
void swap(int *a,int *b);
void swap2(int *a,int *b);
void swap_by_reference(int &x,int &y);
int main()
{
    int i = 42;
    int j = 52;
    int a = 42,b = 92;
    cout<<i<<" has been reset to "<<endl;
    reset(&i);
    cout<<i<<endl;
    /*
    cout<<"a = "<<a<<" b = "<<b<<endl;
    cout<<"&a = "<<&a<<" &b = "<<&b<<endl;
    swap(&a,&b);
    cout<<"a = "<<a<<" b = "<<b<<endl;
    cout<<"&a = "<<&a<<" &b = "<<&b<<endl;
    
    swap2(&a,&b);
    cout<<"a = "<<a<<" b = "<<b<<endl;
    */

    cout<<"a = "<<a<<" b = "<<b<<endl;
    swap_by_reference(a,b);
    cout<<"a = "<<a<<" b = "<<b<<endl;
    /*
    cout<<j<<" has been reset to "<<endl;
    reset2(j);
    cout<<j<<endl;
    */
    return 0;
}

void swap_by_reference(int &x,int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}





void reset(int *ip)
{
    *ip = 0;
}

void reset2(int &p)
{
    p=0;
}
void swap(int *a,int *b)
{
    int *tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void swap2(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
