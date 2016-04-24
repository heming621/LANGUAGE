#include <iostream>
using namespace std;
class B
{
    public:
	int m_iNum;
	B():m_iNum(50){}
    
};

void foo()
{
    const B *b1 = new B();
    //(*b1).m_iNum = 100;            //compiler error
    B *b2 = const_cast<B*>(b1);
    (*b2).m_iNum = 200;
    cout<<"b1:"<<(*b1).m_iNum<<endl; //200
    cout<<"b2:"<<(*b2).m_iNum<<endl; //200

    const B b3;
    //b3.m_iNum = 100;               //compile error
    B b4 = const_cast<B&>(b3);       // b4是另外一个对象
    b4.m_iNum = 200; 
    cout<<"b3:"<<b3.m_iNum<<endl;    //50
    cout<<"b4:"<<b4.m_iNum<<endl;    //200

    const B b5;
    //b5.m_iNum = 100; //error: assignment of member ‘B::m_iNum’ in read-only object

    B &b6 = const_cast<B&>(b5);      // b6是b5的引用；如果对b6的数据成员做改变，就是对b5的值在做改变；
    b6.m_iNum = 200;
    cout<<"b5:"<<b5.m_iNum<<endl;    //200
    cout<<"b6:"<<b6.m_iNum<<endl;    //200

    const B b7;
    B *b8 = const_cast<B*>(&b7);
    b8->m_iNum = 200;
    cout<<"b7:"<<b7.m_iNum<<endl;
    cout<<"b8:"<<(*b8).m_iNum<<endl; //or b8->m_iNum




    const int x = 50;
    int *y = (int*)(&x);             // 同样的地址，但是内容不一样？？？
    *y = 200;
    cout<<"x:"<<x<<"    address:"<<&x<<endl;  //50,地址相同
    cout<<"*y:"<<*y<<"  address:"<<y<<endl; //200，地址相同
    cout<<endl;

    const int xx = 50;
    int* yy = const_cast<int*>(&xx);  //将地址&xx强制转换，去除const属性；const int xx；xx地址也常量？
    *yy = 200;
    cout<<"xx:"<<xx<<"    address:"<<&xx<<endl;  //50，地址相同
    cout<<"*yy:"<<*yy<<"  address:"<<yy<<endl;   //200，地址相同
    cout<<endl;

    const int xxx = 50;
    int yyy = const_cast<int&>(xxx);             //yyy是另外一个int对象
    yyy = 200;
    cout<<"xxx:"<<xxx<<"  address:"<<&xxx<<endl; //50，地址不同
    cout<<"yyy:"<<yyy<<" address:"<<&yyy<<endl;  //200，地址不同
    cout<<endl;
}

void foo1()
{
    const char str1[] = "abc";
    const char str2[] = "abc";
    const char *p1 = "abc";
    const char *p2 = "abc";

    cout<<"str1:"<<str1<<" &str1:"<<&str1<<endl;
    cout<<"str2:"<<str2<<" &str2:"<<&str2<<endl;
    cout<<"p1:"<<p1<<" *p1:"<<*p1<<" &p1:"<<&p1<<endl;
    cout<<"p2:"<<p2<<" *p2:"<<*p2<<" &p2:"<<&p2<<endl;

    if(&str1==&str2)
	cout<<"&str1==&str2"<<endl;
    else
	cout<<"&str1!=&str2"<<endl;
    if(&p1==&p2)
	cout<<"&p1==&p2"<<endl;
    else
	cout<<"&p1!=&p2"<<endl;
}


int main()
{
    foo();
    foo1();
    return 0;
}
