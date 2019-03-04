#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 *"auto"、"for(auto i:v7)",use "g++ -std=c++11 -o test18.exe test18.cpp" to compile.
 * */

int main()
{
    string s("some string");
    string::iterator it0 = s.begin();
    cout<<*it0<<endl;
    if(s.begin()!=s.end())
    {
	string::iterator it = s.begin();
        *it = toupper(*it);
	cout<<*it<<endl;
    }

    for(string::iterator it = s.begin(); it != s.end(); ++it)
    {
	*it = toupper(*it);
    }
    cout<<s<<endl;

    vector<int> v1;
    cout<<v1.size()<<endl;

    vector<string> v8(10,"hi");
    vector<string>::iterator it = v8.begin(); 
    for(int i = 0; i!=v8.size(); i++)
    {
	cout<<v8[i]<<endl;
    }

    vector<string> v7(3,"Bye");
    for(int i = 0; i!=v7.size(); i++)
    {
	cout<<v7[i]<<endl;
    }

    for(vector<string>::iterator iter = v7.begin(); iter != v7.end(); ++iter)
    {
	cout<<*iter<<"="<<endl;
    }

    /*==============================*/
    string str("some string");
    for(auto c:str)
	cout<<c<<endl;
   
    string str1("Hello World!!!");
    int count = 0;
    for(auto i:str1)
    {
	if(ispunct(i))
	    count++;
    }
    cout<<str1<<" has "<<count<<" puntuations!"<<endl;

    vector<string> v6(10,"HH");
    for(auto i:v6)
	cout<<i<<endl;
}
