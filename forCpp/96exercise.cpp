#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
    list<int> lst1;
    list<int>::iterator iter1 = lst1.begin();
    list<int>::iterator iter2 = lst1.end();
    while(iter1!=iter2)  //if '<',  error: no match for ‘operator<’ 
    {


    }


    vector<int> vec;
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(10);
    vector<int>::iterator iterv = vec.begin()+vec.size()/2;
    cout<<*iterv<<endl;



    list<int> lst3(vec.begin(),vec.end());
    //cout<<*(lst3.begin()+lst3.size()/2)<<endl;  // list<int>::iterator does not support operand +、-、<、<=、>、>=
    //cout<<*(lst3.begin()+1)<<endl;              //// list<int>::iterator does not support operand +、-、<、<=、>、>=
    return 0;
}
