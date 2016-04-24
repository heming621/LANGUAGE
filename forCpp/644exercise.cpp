#include <iostream>
using namespace std;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
int main()
{
    string s1,s2;
    cout<<"Input string s1 and s2:"<<endl;
    while(cin>>s1>>s2)
    {
	if(isShorter(s1,s2))
	    cout<<"s1 is shorter than s2.\n";
	else
	    cout<<"s1 is longer than s2.\n";
    }

    return 0;
}
