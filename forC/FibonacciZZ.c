#include <iostream>
using namespace std;
void displayFibonacci(long n);
int main()
{
    displayFibonacci(100);
}

void displayFibonacci(long n)
{
    long f1,f2,tmpf;
    f1 = 1;
    f2 = 1;
    if(n<=1)
	return;
    if(n==2)
	cout<<"1 1";
    cout<<f1;
    while(--n)
    {
        tmpf = f2;
	f2 = f1 + f2;
	f1 = tmpf;
        cout<<" "<<f1;
    }
    cout<<endl;
}
