#include <stdio.h>
int main()
{
    int t,i,j,n,s,sum;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        sum=0;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&s);
            if(s>=0)
            {
                sum=sum+s;
            }
        }
        printf("Case %d: %d\n",i,sum);
    }
}
