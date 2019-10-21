#include <stdio.h>
int main()
{
    long long t,i,n,m,p;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld",&n,&m);
        p=(n*m)/2;
        printf("Case %lld: %lld\n",i,p);
    }
}
