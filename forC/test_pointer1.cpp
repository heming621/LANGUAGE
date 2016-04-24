#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
void fun(double *p1, double *p2, double *s);
void fun2(int **p);
int A = 10, B = 100, *q;
int main()
{
    char *s = "abcdefg";
    fprintf(stderr, "%d\n", s);
    s += 2;
    fprintf(stderr, "%d\n", s);  // output 字符c的地址
    //
    //===================================================
    //
    double a[2] = {1.1,2.2}, b[2] = {10.0,20.0}, *s1 = a;
    fun(a, b, s1);
    printf("%5.2f\n",*s1);
    //
    //=====================================================
    //
    q = &A;       //内容A的地址给了q；
    fun2(&q);     //指针q的地址传了fun2(**p)； 即A的地址的地址（二级指针）作为形参，该指针指向一级指针q；
    //or
    //int *p_A, **p_p_A;
    //p_A = &A;
    //p_p_A = &p_A;
    //fun2(p_p_A);
    //
    //======================================================
    //

    return 0;
}

void fun(double *p1, double *p2, double *s)
{
    s = (double*)calloc(1,sizeof(double));
    *s = *p1 + *p2;
}

void fun2(int **p) //传二级指针, A的地址的地址**A即**p, p --> q --> A
{
    cout<<"fun:&p = "<<&p<<", p = "<<p<<endl;
    *p = &B;
    cout<<"fun:&p = "<<&p<<", p = "<<p<<endl;
}
//二级指针，作为形参，复制的是二级指针的值（即一级指针的地址），其所指向的值不会变化（即所指向的q值不变）；
//解引用*p，得到的是q，故 q = &B
