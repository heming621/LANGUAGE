#include <iostream>
struct Foo{};
std::string global_str;
int global_int;
void print()
{
    int local_int;
    std::cout<<local_int<<std::endl;

}
int main()
{
    std::string local_str;
    int local_int;
    std::cout<<"#"<<global_str<<"#"<<std::endl;
    std::cout<<"#"<<global_int<<"#"<<std::endl;
    std::cout<<"#"<<local_str<<"#"<<std::endl;
    std::cout<<"#"<<local_int<<"#"<<std::endl;
    return 0;
}
