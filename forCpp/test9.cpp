#include <iostream>
using namespace std;
int count_called();
size_t count_called2();
int main()
{
    int i;
    for(i=0;i!=10;i++)
    {
	static size_t ctr = 0;
	cout<<++ctr<<endl;
       // cout<<count_called2()<<endl;
    }
    //static size_t ctr = 1;
    cout<<++ctr<<endl;
    return 0;
}

size_t count_called2()
{
    static size_t ctr = 0;
    return ++ctr;
}
