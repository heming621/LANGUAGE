#include <iostream>
#include <string>
#include <fstream>
#include <iteration>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
const int nCities = 99;
const double SPEED = 0.98;
const int INITIAL_TEMP = 1000;
const ing L = 100*nCities;
struct node
{
    int num;
    int x;
    int y;
}nodes[nCities];

struct unit
{
    double length;
    int path[nCities];
    bool operator < (const struct unit &other) const
    {
	return length < other.length;
    }
};

unit bestone = {INT_MAX, {0}};
double length_table[nCities][nCities];

void init_dis();
void SA_TSP();
void Calculate_length(unit &p);
void print(unit &p);
void getNewSolution(unit &p);
bool Accept(unit $bestone, unit &temp, double t);

int main()
{
    return 0;
}

class GenbyOne
{
    public:
	GenbyOne(int _seed = -1):seed(_seed){}
	int operator() (){return seed += 1;}
    private:
	int seed;
};
