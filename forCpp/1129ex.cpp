#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{
    map<string, vector<int> > m = {{"Alan",{1,2,3,4,5}},{"John",{1,5,6,7,100,19,2,3}}};
    map<string, vector<int>>::iterator it1 = m.find("Alan");
    auto it2 = m.find("John");
    cout<<(*it1).first<<endl;
    cout<<it2->first<<endl;
    

    /****************************/
    cout<<m.count("John")<<endl;
    return 0;

}
