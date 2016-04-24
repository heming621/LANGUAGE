#include <iostream>
#include <vector>
#include <memory>
using namespace std;
int main()
{
    shared_ptr<vector<int>>  vec = make_shared<vector<int>>();
    
    return 0;
}
