#include <iostream>
using namespace std;
void swap(int &a,int &b);
int main()
{
    char str[]  = "1234";

    swap(a,b);
    return 0;
}
void swap(int &a,int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
