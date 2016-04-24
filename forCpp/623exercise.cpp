#include <iostream>
using namespace std;
void print2(const int* begin, const int* end);
void print3(const int* ia, const int size);
void print4(const int ia[], const int size);
int main()
{
    int i = 0, j[5] = {0,1,2,3,4};
    print2(begin(j),end(j));
    cout<<"begin(j) = "<<begin(j)<<endl<<"&j[0] = "<<&j[0]<<endl;
    cout<<"end(j) = "<<end(j)<<endl<<"&j[n] = "<<&j[5]<<endl;
    cout<<j[6]<<endl<<j[7]<<endl;
    cout<<&j[6]<<endl<<&j[7]<<endl;
    cout<<"j's size is "<<end(j)-begin(j)<<endl;
    
    print3(j, end(j)-begin(j));
    cout<<endl;
    print4(j, end(j)-begin(j));    
    cout<<endl;
    print4(j, &j[5]-&j[0]);
    return 0;
}

void print2(const int* begin, const int* end)
{
    for(; begin!=end; )
	cout<<*(begin++)<<endl;
}

void print4(const int ia[], const int size)
{
    for(int i=0; i<size; i++)
    {
	cout<<ia[i]<<endl;
    }
}

void print3(const int* beg, const int size)
{
    for(int i=0; i<size; i++)
    {
//	cout<<*ia++<<" ";
	cout<<beg[i]<<endl;
    }
}

