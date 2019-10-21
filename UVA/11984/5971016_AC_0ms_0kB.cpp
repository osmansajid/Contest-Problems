#include <stdio.h>
int main()
{
    int t,i;
    float c,d,n,m,k;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%f %f",&c,&d);
        k=((9*c)/5)+32;
        n=d+k;
        m=((n-32)*5)/9;
        printf("Case %d: %.2f\n",i,m);
    }

}
