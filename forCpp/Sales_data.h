#include <iostream>
using namespace std;
struct Sales_data
{
    string isbn()const{return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    string bookNo;
    unsigned units_sold;
    double revenue;
};




Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold>>price;
    item.revenue = price*item.units_sold;
    return is;
}

ostream &print(ostream &os, Sales_data &item)
{
    os << item.bookNo << " " << item.units_sold << " " <<item.revenue<<" "<<item.avg_price();
    return os;
}
