#include <stdio.h>
int main()
{
    int t,i,j,n,m,z;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
         z=0;
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&m);
            if(m>z)
            {
                z=m;
            }

        }
        printf("Case %d: %d\n",i,z);

    }
}
