#include <iostream>
#include <string>
using namespace std;
bool str_substring(const string &str1, const string &str2);
int main()
{

    return 0;
}

bool str_substring(const string &str1, const string &str2)
{
    if(str1.size() == str2.size())
	return str1==str2;   //正确，返回布尔值
    int size = (str1.size() < str2.size())?str1.size():str2.size();
    
    for(int i = 0; i!=size; i++)
    {
	if(str1[i]!=str2[i])
	    return;
    }
    
}
