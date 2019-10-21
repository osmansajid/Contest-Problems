#include <stdio.h>
int main()
{
    int t,i,j,p,n,temp,l,count,k;
    int a[1000];
    int b[1000];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        j=0;
        count=0;
        scanf("%d",&n);
        while(n!=0)
        {
            a[j]=n%2;
            p=n/2;
            n=p;
            j++;
        }
        for(k=0;k<j;k++)
        {
            if(a[k]==1)
            {
                count++;
            }
        }
        if(count%2==0)
        {
            printf("Case %d: even\n",i);
        }
        else
        {
            printf("Case %d: odd\n",i);
        }
    }
}