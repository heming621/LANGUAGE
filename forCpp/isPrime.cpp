#include <iostream>
#include <math.h>
using namespace std;
int isPrime(int n);
long sum(int);
int main()
{
    int n;
    cin>>n;
    for(int i=2; i<=n; i++)
	if(isPrime(i))
	    cout<<i<<" ";
    cout<<endl;
    cout<<"The sum of primes in "<<n<<" is "<<sum(n)<<endl;
    return 0;
}

int isPrime(int n)
{
    if(n<2)
	return 0;
    int k = (int)sqrt(n);
    for(int i=2; i<=k; i++)
    {
	if(n%i==0)
	    return 0;
    }
    return 1;
}

long sum(int n)
{
    long s=0;
    for(int i=2;i<=n;i++)
    {
	if(isPrime(i))
	{
	    s+=i;
	}
    }
    return s;
}


