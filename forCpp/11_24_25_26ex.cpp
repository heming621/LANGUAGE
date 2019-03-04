#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
using namespace std;
int main()
{
    map<int, string> m = {{1,"ss"},{2,"sz"}};
    using KeyType = map<int, string>::key_type;

    cout<<"type ot subscript:"<<typeid(KeyType).name()<<endl;
    cout<<"returned from the subscript operator:"<<typeid(decltype(m[2])).name()<<endl;

    using ValueType = map<int, string>::mapped_type;
    cout<<"type ot subscript:"<<typeid(KeyType).name()<<endl;
    cout<<"returned from the subscript operator:"<<typeid(ValueType).name()<<endl;


    cout<<typeid(int).name()<<endl;     //i
    cout<<typeid(int*).name()<<endl;    //Pi
    cout<<typeid("aa").name()<<endl;    //A3_c
    //cout<<typeid(long)<<endl;
    return 0;
}
