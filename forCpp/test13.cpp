#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v2;
    vector<string> text;
    string word;
    for(int i = 0; i != 10; ++i)
    {
	v2.push_back(i);
    }

    for(int i = 0; i != v2.size(); i++)
    {
	cout<<v2[i]<<endl;
    }
    
    while(cin>>word&&word!="###")
    {
	text.push_back(word);
    }

    for(int i = 0;i < text.size();i++)
    {
	cout<<text[i]<<endl;
    }
    
    for(auto &r : text)
    {
	cout<<&r<<endl;
    }
    return 0;
}
