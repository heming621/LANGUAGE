#include <iostream>
#include <stdio.h>
using namespace std;
 
void printA(int n)
{
    int nt,it;
    for(int i=1; i<=n; i++)
    {
	nt=n-i;
	while(nt--)
	    cout<<' ';
	it=i*2-1;
	while(it--)
	    cout<<'*';
	cout<<endl;

    }
}

void printV(int n)
{
    int nt,it;
    for(int i=1; i<=n; i++)
    {
	it=i;
	while(it--)
	    cout<<' ';
	nt=2*(n-i+1)-1;
	while(nt--)
	    cout<<'*';
	cout<<endl;

    }
}
int main()
{
    //int a,b,c;
    //a=b+c=1;
  
    const int N=20;
    printA(N);
    printV(N-1);
    
    

    
    
    /*
    float F,C;
    while(1)
    {
        cin>>F;
        printf("%0.2f\n",(5*(F-32))/9);
	//cout<<(5*(F-32))/9<<endl;
    }
    */


    /*
    char c1, c2;
    c1='a';
    c2='b';
    c1-=32;
    c2-=32;
    cout<<c1<<' '<<c2<<endl;
    */


     /*
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
     */




    /*
    int x, y;
    x=2;
    y=2.75+x/2;
    cout<<y<<endl;

    x=10;
    y=10;
    cout<<x--<<' '<<--y<<endl;
    */


    /*
    int x=3;
    int y;
    do
    {
	y=x--;
	if(!y)
	{
	    cout<<"*";
	    continue;
	}
	cout<<"#";
    }while(x=2);
    */ // output "###################"

    /*
    int x=0, s=0;
    while(!x!=0)s+=++x;
    cout<<s<<endl;
    */

    /*
    int a=-1, b=1, k;
    if((++a)<0&&(b--<=0))
	cout<<a<<' '<<b<<endl;
    else
	cout<<b<<' '<<a<<endl;  // output "1 0" , a has changed, b didn't change.
    */

    /*
    int x=1, a=0, b=0;
    switch(x)
    {
	case 0:b++;  //break;
	case 1:a++;  //berak;
	case 2:a++;b++;
    }
    cout<<a<<" "<<b<<endl;  //output "2 1", 
    */


    /*
    int a=-1,b=4,k;
    k=(++a<=0)&&(b--<0)
	;
    cout<<k<<" "<<a<<" "<<b<<endl;
    */

    /*
    int i,j,m,n;
    i=8;
    j=10;
    m=++i;
    n=j++;
    cout<<i<<" "<<j<<" "<<m<<" "<<n<<endl; 
    */    
    
    /*
    const char a = 65; 
    cout<<a<<endl;  // output 'A'
    */

    /*
    int x=10, y=3;
    cout<<(y=x/y)<<endl;
    */
    return 0;
}
