#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    map<string, size_t> word_count;
    string word;
    set<string> exclude = {"The","But","Adn","Or","An","A","the","but","and","or","an","a"};
    while(cin>>word&&word!="###")
    {
	if(exclude.find(word)==exclude.end())
	++word_count[word];
    }
    for(const auto &w:word_count)
    {
	cout<<w.first<<" occurs "<<w.second<<((w.second>1)?" times":" time")<<endl;
    }
    return 0;
}
