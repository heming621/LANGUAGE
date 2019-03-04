#include <iostream>
#include <string>
using namespace std;
class Person
{
    private:
	string name;
	int age;
    public:
	Person(string n, int a)
	{
	    name = n;
	    age = a;
	}
	void outName();
	void outAge();
};

void Person::outName()
{
    cout<<name<<endl;
}

void Person::outAge()
{
    cout<<age<<endl;
}

int main()
{
    Person p("HM",21);
    p.outAge();
    p.outName();
    return 0;
}
