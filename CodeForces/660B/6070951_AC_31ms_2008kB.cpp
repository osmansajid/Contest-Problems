#include <stdio.h>
int main()
{
    int i,j,k,m,n,q,p;
    int a[1000][4];
    p=1;
    scanf("%d %d",&n,&m);
    for(i=0;i<n ;i++)
    {
        a[i][0]=p;
        a[i+1][0]=p+2;
        a[i+1][3]=p+3;
        a[i][3]=p+1;
        p=a[i+1][3]+1;
        i++;
    }
    q=a[n-1][3]+1;
    for(j=0;j<n;j++)
    {
        a[j][1]=q;
        a[j][2]=q+1;
        a[j+1][1]=q+2;
        a[j+1][2]=q+3;
         q=a[j+1][2]+1;
        j++;
    }
    for(k=0;k<n;k++)
    {
     if(a[k][1]<=m)
     {
          printf("%d ",a[k][1]);
     }
     if(a[k][0]<=m)
     {
          printf("%d ",a[k][0]);
     }
     if(a[k][2]<=m)
     {
          printf("%d ",a[k][2]);
     }
     if(a[k][3]<=m)
     {
         printf("%d ",a[k][3]);
     }

    }
}
