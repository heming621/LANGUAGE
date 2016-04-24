#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi;
    int val;
    /*
    for(int i=0;i<10;i++)
    {
	cin>>val;
	vi.push_back(val);
    }
    */
    for(int i; cin>>i; vi.push_back(i));


    for(int i = 0; i<vi.size(); i=i+2)
    {
	cout<<vi[i]+vi[i+1]<<" ";
         
    }
    cout<<endl;
    int i = 0,j = vi.size()-1;
    /*
    for(; i!=j; i++,j--)
    {
	cout<<vi[i]+vi[j]<<endl;
	if(i==j-1)
	    break;
    }*/
     for(; i!=j&&i!=j-1; i++,j--)
     {
         cout<<vi[i]+vi[j]<<" ";
     }
    cout<<vi[i]+vi[j]<<endl;

    return 0;
}
