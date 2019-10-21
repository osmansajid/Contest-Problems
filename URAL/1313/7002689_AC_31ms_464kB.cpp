#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,p,j;
    cin>>n;
    int a[n+5][n+5];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {
        p=i;
         for(j=1;j<=i;j++)
        {
            printf("%d ",a[p][j]);
            p--;
        }
    }
    int q=2;
    for(j=q;j<=n;j=++q)
    {
        for(i=n;i>=q;i--,j++)
        {
            printf("%d ",a[i][j]);
        }
    }
}
