#include <iostream>
using namespace std;
class Person
{
    private:
	string name;
	string address;
    public:
	Person();
	Person(string,string);
	void setName(string nn);
	void setAddress(string aa);
	string getName();//{return name;}
	string getAddress();//{return address;}
};

Person::Person(){}

Person::Person(string nn,string aa)
{
    name = nn;
    address = aa;
    
}

void Person::setName(string nn)
{
    name = nn;
}
void Person::setAddress(string aa)
{
    address = aa;
}
string Person::getName()
{
    return name;
}
string Person::getAddress()
{
    return address;
}

istream &read(istream &is, Person &p)
{
    string x,y;
    is>>x>>y;
    p.setName(x);
    p.setAddress(y);
    //is>>p.getName()>>p.getAddress();
    return is;
}

ostream &print(ostream &os, Person &p)
{
    os<<p.getName()<<" "<<p.getAddress();
    return os;
}


