#include <stdio.h>
#include <math.h>
int main()
{
    double x1,y1;
    double x2,y2;
    while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
    {
	double result;
	result = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	printf("%.2lf\n",result);
    }
//	printf("%.2f\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    return 0;
}

//gcc -o test19.o test19.c -lm
