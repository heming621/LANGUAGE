#include <iostream>
using namespace std;
void printH(void);
int I;
int main()
{
    static int i;
    static int h;
    cout<<"I="<<I<<endl;
    cout<<"i="<<i<<endl;
    cout<<"h="<<h<<endl;
    cout<<"H="<<printH<<endl;
    return 0;
}

void printH(void)
{
    int H;
    cout<<"H="<<H<<endl;
}
