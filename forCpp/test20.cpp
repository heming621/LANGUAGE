#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <string>
using namespace std;
int main()
{
    multimap<string, string> authors;
    authors.insert({"Barth, John","Sot-Weed Factor"});
    authors.insert({"Barth, John","Lost in the Funhouse"});
    
    string search_item("Alain de Bottom");
    auto entities = authors.count(search_item);
    auto iter = authors.find(search_item);
    while(entities)
    {
	cout<<iter->first<<endl;
	++iter;
	--entities;
    }


    /*
    int val = 83;
    int ia[] = {27, 210, 12, 47, 109 ,83};
    cout<<find(begin(ia),end(ia),val)<<endl;;
    */
    return 0;
}
