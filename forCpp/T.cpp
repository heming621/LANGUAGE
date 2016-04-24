nclude <iostream>
using namespace std;
int main()
{
    int n;
    int a[1000][1000];
    int var = 1;
    int i,j;
    cin>>n;
    for(int i = 0; i<=n+1; i++)
        for(int j = 0; j<=n+1; j++)
             a[i][j]=0;
  
    i=1;
    j=1;
    var = 1;
    a[i][j]=var;
    while(var<n*n)
    {
          while((j+1)<=n&&a[i][j+1]==0)a[i][++j]=++var;
          while((i+1)<=n&&a[i+1][j]==0)a[++i][j]=++var;
          while((j-1)>=1&&a[i][j-1]==0)a[i][--j]=++var;
          while((i-1)>=1&&a[i-1][j]==0)a[--i][j]=++var;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
               cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}

