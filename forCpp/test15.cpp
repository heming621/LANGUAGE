#include <iostream>
using namespace std;
const string &shorterString(const string &s1, const string &s2);
char &get_val(string &str, string::size_type ix);
int main()
{
    string str("a value");
    get_val(str,0)='A';
    cout<<str<<endl;
    cout<<shorterString("hi","bye")<<endl;
    return 0;
}

const string &shorterString(const string &s1, const string &s2)
{
    return s1.size()<=s2.size()?s1:s2;
}

char &get_val(string &str, string::size_type ix)
{
    return str[ix];
}
