#include <iostream>
#include "Sales_item.h"
using namespace std;
int main()
{
    Sales_item item3, item4, item5;
    cin>>item3>>item4>>item5;
    cout<<item3.units_sold<<endl;
    cout<<item4.units_sold<<endl;
    cout<<item5.units_sold<<endl;
    return 0;
}
