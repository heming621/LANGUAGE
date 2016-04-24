#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> veci;
    int val;
    for(int i=0; i<10; i++)
    {
	cin>>val;
	veci.push_back(val);
    }

    //for(int i:veci) //c++11
    for(int i=0; i<10; i++)
	cout<<veci[i]<<" ";
    cout<<endl;
 

    for(vector<int>::iterator it=veci.begin(); it!=veci.end(); it++)
    {
	cout<<(*it)*2<<" ";
	
    }
    cout<<endl;
    return 0;
}
