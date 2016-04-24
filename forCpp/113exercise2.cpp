#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<string, size_t> word_count;
    string val;
    while(cin>>val)
    {
	word_count[val]++;
    }

    for(auto &i:word_count)
    {
	cout<<
    }
}
