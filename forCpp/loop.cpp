#include <iostream>
using namespace std;
int main()
{
    const int N = 4;
    int n = 16;
    int count;
    int i,j;
    int arr[N+2][N+2];
    for(i=0;i<=N+1; i++)
	for(j=0;j<N+1;j++)
	    arr[i][j]=0;
   
    count=1;
    j=1;
    i=1;
    arr[i][j++]=count++;
    while(count<=16)
    {
	while(j<=N&&!arr[i][j+1])arr[i][++j]=count++;j=j-1;
	while(i<=N&&!arr[i+1][j])arr[++i][j]=count++;i=i-1;
	while(j>=1&&!arr[i][j-1])arr[i][--j]=count++;j=j+1;
	while(j<=N-1&&!arr[i-1][j])arr[i--][j]=count++;i=i+1;
    }

    for(i=0;i<=N+1; i++)
    {
	for(j=0;j<N+1;j++)
            arr[i][j]=0;
	cout<<endl;
    }
    return 0;
}
