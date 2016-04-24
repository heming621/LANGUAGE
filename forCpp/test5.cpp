#include <iostream>
#include <string>
using namespace std;
int main()
{
    /*
    int val;
    while(std::cin>>val&&val!='#')
    {
	std::cout<<"Yes!"<<std::endl;
    }
    std::cout<<"No!"<<std::endl;
    */
    string str1;
    while(std::cin>>str1)
    {
	std::cout<<"Yes!";
    }
    std::cout<<"No!";

    return 0;
}
