#include <iostream>
#include <vector>
using namespace std;
int main()
{

    vector<int> ivec;
    vector<vector<string> > file;


    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;
    std::cout<<"The value of ival\n"<<"direct value:"<<ival<<"\n"<<"indirect value:"<<*pi<<"\n"<<"doubly indirect value:"<<**ppi<<std::endl;



    int i = 42;
    void* p = &i;
    //long *lp = &i;
    //int i = 0;
    //double *dp = &i;
    //int *ip=i;
    //int *p = &i;
    /*
    int i = 13;
    int *p1 = &i;
    std::cout<<"i = "<<i<<std::endl;
    std::cout<<"p1 = "<<*p1<<std::endl;
    std::cout<<"*p1 * *p1 = "<<*p1**p1<<std::endl;
    std::cout<<"p1 = "<<p1<<std::endl;
    */

}
