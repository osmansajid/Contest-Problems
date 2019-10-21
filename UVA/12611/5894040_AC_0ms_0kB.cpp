#include <stdio.h>
int main()
{
    double t,e,i,l,w,p,q,r,s,a,b,c,d;
    scanf("%lf",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf",&e);
        l=(e*10)/2;
        w=(e*6)/2;
        p=-(l*45)/100;
        q=w/2;
        r=(l*55)/100;
        s=w/2;
        a=p;
        b=-q;
        c=r;
        d=-s;
        printf("Case %0.lf:\n",i);
        printf("%0.lf %0.lf\n",p,q);
        printf("%0.lf %0.lf\n",r,s);
        printf("%0.lf %0.lf\n",c,d);
        printf("%0.lf %0.lf\n",a,b);
    }
}
