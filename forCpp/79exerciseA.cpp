#include <iostream>
#include "Sales_item.h"
using namespace std;
struct Person
{
    string name, address;
    string getName()const
    {
	return name;
    }
    string getAddress()const
    {
	return address;
    }
};
istream &read(istream &is, Person &per)
{
    is>>per.name>>per.address;
    return is;
}
ostream &print(ostream &os, Person &per)
{
    os<<per.getName()<<" "<<per.getAddress()<<endl;
    return os;
}
int main()
{

    Person p;
    read(cin,p);
    print(cout,p);
    return 0;
}
