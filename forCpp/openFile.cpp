#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    char filename[20];
    strcpy(filename, "/home/zhm/forCpp/test5.cpp");
    ifstream fin;
    fin.open(filename);

    fstream file1;
    file1.open("/home/zhm/forCpp/test5.cpp");
    return 0;
}
