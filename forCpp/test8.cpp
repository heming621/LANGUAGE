#include <iostream>
using namespace std;
const double eps=1e-10;
void fact(void);
int main()
{
    fact();
    return 0;
}
void fact(void)
{
    int sum,val;
    sum = 1;
    cout<<"Input the value of val:"<<endl;
    cin>>val;
    if(val<0||(val-(double)(int)val)<eps)
    {
	while(val>0)
	{
            sum*=val--;
	}
    }	
    else
	cout<<"Input the positive integer!";
    cout<<"The "<<val<<"! is "<<sum<<endl;
}
