#include <iostream>
using namespace std;
int main()
{
    int m,n;
    int flag,tmp;
    while(cin>>m>>n && 100<=m && m<=n && n<=999)
    {
	flag = 0;
	for(;m<=n;m++)
	{
	    tmp = (m%10)*(m%10)*(m%10) + (m/10%10)*(m/10%10)*(m/10%10) + (m/100)*(m/100)*(m/100);
	    if(tmp==m)
	    {
		if(flag)
		    cout<<" ";
		cout<<m;
		flag++;
	    }
	}
	if(!flag)
	    cout<<"no"<<endl;
	else
	    cout<<endl;
    }
    return 0;
}
