#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
int main()
{
    map<string, list<size_t>> m;
    map<vector<int>::iterator, int> mv;
    map<list<int>::iterator, int> ml;

    vector<int> vi;
    mv.insert(pair<vector<int>::iterator, int>(vi.begin(), 0));

    list<int> li;
    ml.insert(pair<list<int>::iterator, int>(li.begin(), 0));
    //how about push_back()?
    return 0;
}
