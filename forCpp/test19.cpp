#include <iostream>
#include <math.h>
using namespace std;

class CCTest
{
    public:
	void setNumber(int);
	void printNumber() const;
    private:
	int number;
};

void CCTest::setNumber(int num)
{
    number = num;
}
void CCTest::printNumber()const
{
    cout<<"\nBefore:"<<number;
    const_cast<CCTest*>(this)->number--;
    cout<<"\nAfter:"<<number;
}


int main()
{

    CCTest X;
    X.setNumber(8);
    X.printNumber();
    /*
    double x1,y1;
    double x2,y2;
    while(cin>>x1>>y1>>x2>>y2)
    {
	cout<<sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<<endl;
    }
    */
    return 0;
}
