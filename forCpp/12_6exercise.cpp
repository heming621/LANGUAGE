#include <iostream>
#include <vector>
using namespace std;
using p_iv = vector<int>*;

vector<int>* readVec(vector<int>* iv);
void printVec(vector<int> *iv);
void Test01();
auto make_dynamically()->p_iv;
auto populate(p_iv vec)->p_iv;
void Test02();
int main()
{
    //01
    Test01();  
    //02 way 2nd
    Test02();
    return 0;
}

vector<int>* readVec(vector<int>* iv)
{
    for(int i = 1; i <= 10; i++)
    {
	(*iv).push_back(i); //iv->push_back(i);
    }
    return iv;
}

void printVec(vector<int> *iv)
{
    for(vector<int>::iterator beg = (*iv).begin(); beg!=(*iv).end(); beg++)
    {
	cout<<*beg<<" ";
    }
    cout<<endl;
}

void Test01()
{
    vector<int> *iv = new vector<int>{};
    iv = readVec(iv);
    printVec(iv);
    delete iv;
}

auto make_dynamically()->p_iv  //返回一个新生成的p_iv类型的对象；尾置返回类型，前加auto后加->返回类型；
{
    return new vector<int>{};
}

auto populate(p_iv vec)->p_iv  //函数作用：将传入的iv每次push_back一个数字；
{
    for(int tmp; cout<<"Pls enter:\n", cin>>tmp&&tmp!=-1; vec->push_back(tmp));
    return vec;
}

auto print(p_iv vec)->ostream&
{
    for(auto tmp:*vec)
	cout << tmp << " ";    //流对象，每次tmp输入到cout对象中；返回类型是ostream；
    return cout;
}

void Test02()
{
    p_iv vec = make_dynamically();
    vec = populate(vec);
    print(vec);
}


















