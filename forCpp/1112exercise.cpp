#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string str;
    int i;
    pair<string, int> p;
    vector<pair<string, int>> vec;
    
    while(cin>>str>>i&&str!="###")
    {
	p.first = str;
	p.second = i;
	vec.push_back(p);
        //or
	vec.push_back(pair<string, int>(str, i));
	vec.push_back(make_pair(str, i));
	vec.push_back({str, i});
	vec.emplace_back(str, i);
    }

    for(int i=0; i<vec.size(); i++)
	cout<<vec[i].first<<" "<<vec[i].second<<endl;
   
    //another for
    for(auto &p:vec)
    {
	cout<<p.first<<":"<<p.second<<endl;
    }
    
    //another for
    for(vector<pair<string, int>>::iterator beg=vec.begin(); beg!=vec.end(); beg++)
	cout<<(*beg).first<<"::"<<(*beg).second<<endl;

    return 0;
}
