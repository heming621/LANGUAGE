#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> veci;
    int size1;
    for(int val; cin>>val; veci.push_back(val));

    if(veci.empty())
    {
	cout<<"The vector is empty!";
        return -1;
    }

    if(veci.size()==1)
    {
	cout<<"only one integer "<<veci[0]<<", it doesn't have any adjacent elements."<<endl;
	return -1;
    }
    for(vector<int>::iterator it=veci.begin(); it!=veci.end()-1;it++)
	cout<<*it+*(it+1)<<" ";
    cout<<endl;

    if(veci.size()%2)
	size1 = veci.size()/2+1;
    else
	size1 = veci.size()/2;

    for(vector<int>::iterator ib=veci.begin(),ie=veci.end()-1; ib<=ie; ib++,ie--)
    {
	cout<<*ib+*ie<<" ";
    }
    cout<<endl;
    
    return 0;
}
