#include<stdio.h>
#include <algorithm>
int main()
{
    int n,m,sum,i,p,j,k,l;
    int a[1000];
    int b[1000];
    int c[1000];
    scanf("%d %d",&n,&m);
        sum=0;
        j=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&p);
            a[i]=p;
        }
        for(i=0;i<n;i++)
        {
            if(a[i]<0)
            {
                b[j]=(-1)*a[i];
                j++;
            }
        }
        if(j>m)
       {
          std::sort(b,b+j);
           for(k=j-1,l=0;k>=0,l<j;k--,l++)
           {
               c[k]=b[l];
           }
           for(k=0;k<m;k++)
           {
               sum=sum+c[k];
           }
           printf("%d",sum);
       }
       else
       {
          for(i=0;i<n;i++)
        {
            if(a[i]<0)
            {
                sum=sum+(-1)*a[i];
            }
        }
           printf("%d",sum);
       }
}
