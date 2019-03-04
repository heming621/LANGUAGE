/*
 *Sum of factors.
 * 
 * */

#include <iostream>
using namespace std;
void outputFac(int n);
int main()
{

    outputFac(15);
    return 0;
}

void outputFac(int n)
{
    int temp=0;
    while(n)
    {
	temp+=n%10;
	n/=10;
    }
    cout<<temp<<endl;
}
