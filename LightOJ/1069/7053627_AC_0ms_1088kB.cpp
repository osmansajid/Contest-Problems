#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,p,q,m,n,i,t,e,f;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&a,&b);
        e=abs(a-b);
        p= e*4;
        q=p+6;
        m=a*4;
        n=m+13;
        f=q+n;
        printf("Case %d: %d\n",i,f);
    }
}
