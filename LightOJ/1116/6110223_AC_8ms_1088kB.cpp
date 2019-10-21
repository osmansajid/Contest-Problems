#include <stdio.h>
int main()
{
    long long t,n,m,w,i,j,p;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&w);
        if(w%2!=0)
        {
            printf("Case %lld: Impossible\n",i);
        }

        else
        {
            p=w;
            while(w%2==0)
            {
                n=w/2;
                w=n;
            }
            m=p/n;
            printf("Case %lld: %lld %lld\n",i,n,m);
        }
    }
}
