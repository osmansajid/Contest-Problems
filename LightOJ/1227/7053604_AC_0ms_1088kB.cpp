#include <stdio.h>
int main()
{
    int t,n,m,p,i,j,r,q,k,count;
    int a[100];
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {    j=0;
        scanf("%d %d %d",&n,&p,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&r);
            a[j]=r;
            j++;
        }
        m=0;
        count=0;
        for(i=0;i<n;i++)
        {
            m=m+a[i];
            if(m>q)
            {
                break;
            }
            count++;
            if(count==p)
            {
                break;
            }
        }
        printf("Case %d: %d\n",k,count);

    }
}
