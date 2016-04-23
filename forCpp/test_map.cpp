/*
 * Test of map,
 * Including insert data((string, string), (string, vector<string>)) into map, 
 * output data of map;
 * */

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef map<string, string> MAP_S2S;
typedef map<string, vector<string> > MAP_S2V; 
int main()
{
    map<string, string> mt;
    map<string, vector<string> > mv;
    mt.insert(MAP_S2S::value_type("2001","test1"));
    mt.insert(pair<string, string>("2005","test5"));
    mt.insert(make_pair("2002","test2"));
    mt.insert({"2003","test3"});
    mt.emplace("2004","test4");  // easiest way!!! Like vector.emplace_back(map<string, int>);

    map<string, string>::const_iterator beg = mt.begin();
    for(;beg!=mt.end(); beg++)
    {
	cout<<beg->first<<" "<<beg->second<<endl;      //output1
	cout<<(*beg).first<<" "<<(*beg).second<<endl;  //output2
    }
    cout<<"///////////////////////"<<endl;

    vector<string> vec1;
    vec1.emplace_back("test1_vector1");
    vec1.emplace_back("test1_vector2");
    vec1.emplace_back("test1_vector3");
    vec1.emplace_back("test1_vector4");
    vector<string> vec2;
    vec2.emplace_back("test2_vector1");
    vec2.emplace_back("test2_vector2");
    vec2.emplace_back("test2_vector3");
    vec2.emplace_back("test2_vector4");
    mv.insert(MAP_S2V::value_type("10001",vec1));
    mv.insert(MAP_S2V::value_type("10002",vec2));
    //Output map<string, vector<string>>, one maps more; 
    for(MAP_S2V::iterator mbeg=mv.begin(); mbeg!=mv.end(); mbeg++)
    {
	cout<<(*mbeg).first<<"\t\t";
	for(vector<string>::iterator vbeg=(*mbeg).second.begin(); vbeg!=(*mbeg).second.end(); vbeg++)
	{
	    cout<<*vbeg<<" ";
	}
	cout<<endl;
    }
    cout<<"//////////////////////////"<<endl;


    return 0;
}


