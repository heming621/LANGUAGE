#include <stdio.h>
int main()
{
    int num, i, j, k, place;
    scanf("%d",&num);
    if(num>99)
	place=3;
    else if(num>9)
	place=2;
    else
	place=1;

    i=num/100;
    j=(num-i*100)/10;
    k=(num-i*100-j*10);
    switch(place)
    {
	case 3:cout<<k<<j<<i<<endl;break;
        case 2:cout<<k<<j<<endl;break;
	case 1:cout<<k;
    }

    /*
    char ch;
    scanf("%3c",&ch);
    printf("%c\n",ch);

    char a,b;
    scanf("%2c%3c",&a,&b);
    printf("a=%c,b=%c\n",a,b);
    */
    return 0;
}
