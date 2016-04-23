#include <iostream>
using namespace std;

class Foo
{
    public:
	Foo()
	{
	    this->value = 0;
	}

	Foo get_copy()                //函数的返回类型是Foo，返回当前对象的拷贝；//this是指针，指向当前对象的指针；
	{
	    return *this;
	}
	Foo& get_copy_as_reference()  //函数的返回类型是Foo&，返回当前对象的拷贝的引用？
	{
	    return *this;
	}
	Foo* get_pointer()            //函数的返回类型是Foo*，返回当前对象的指针；
	{
	    return this;
	}

	void increment()              //将当前对象的数据成员value自加；
	{
	    this->value++;
	}

	void print_value()
	{
	    cout << this->value << endl;
	}
    private:
	int value;
};

int main()
{
    Foo foo;
    foo.increment();
    foo.print_value();
    
    foo.get_copy().increment();                //其它函数都是获取当前对象，该函数获取当前对象的拷贝，此时当前对象已经是0++=1；
    foo.print_value();

    foo.get_copy_as_reference().increment();   //获取当前对象的拷贝，的引用；
    foo.print_value();

    foo.get_pointer()->increment();
    foo.print_value();

    return 0;
}
