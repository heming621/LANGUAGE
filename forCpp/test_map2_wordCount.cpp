#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<string, size_t> word_count;
    string word;
    while(cin>>word&&word!="###")
    {
	auto ret = word_count.emplace(word, 1);
        if(!ret.second)
	    ++(*(ret.first)).second;
    }
    for(map<string, size_t>::iterator beg=word_count.begin(); beg!=word_count.end(); beg++)
    {
	cout<<(*beg).first<<"\t"<<(*beg).second<<endl;
    }
    return 0;
}
