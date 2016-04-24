#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    map<string,vector<string>> family;
    string lastName,chldName;
    
    while([&]()->bool{
	        cout<<"PLS enter last name:\n";
		return cin>>lastName && lastName != "@q";
		}()	    
	    )
    {
	cout<<"PLS Enter children's name:\n";
	while(cin>>chldName && chldName != "@q")
	{
	    family[lastName].push_back(chldName);
	}

    }

    for(auto e:family)
    {
	cout<<e.first<<":\n";
	for(auto c:e.second)
	    cout<<c<<" ";
	cout<<endl;
    }

    return 0;
}
