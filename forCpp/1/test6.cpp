#include <iostream>
#include "Sales_item.h"
int main()
{
    int i,&ri = i;
    i = 5;
    ri = 10;
    std::cout<<"i is "<<i<<std::endl<<"ri is "<<ri<<std::endl;
    i=20;
     std::cout<<"i is "<<i<<std::endl<<"ri is "<<ri<<std::endl;
    /*
     *
    Sales_item book;
    std::cin>>book;
    std::cout<<book<<std::endl;
    */
    return 0;
}
