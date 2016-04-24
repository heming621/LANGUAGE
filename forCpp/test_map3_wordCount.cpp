#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, size_t> ms;
    string val;
    while(cin>>val&&val!="###")
    {
	ms[val]++;
    }
    for(auto &i:ms)
    {
	cout<<i.first<<":"<<i.second<<endl;
    }
    return 0;
}
