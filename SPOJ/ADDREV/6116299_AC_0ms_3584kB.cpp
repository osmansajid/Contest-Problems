#include <stdio.h>
int main()
{

    long long a,b,i,t,j,k,l,p,q,n,result,r;
    long long c[10000];
    long long d[10000];
    long long e[10000];
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld",&a,&b);
        j=0;
        while(a!=0)
        {
            c[j]=a%10;
            a=a/10;
            j++;
        }
        k=0;
        while(b!=0)
        {
            d[k]=b%10;
            b=b/10;
            k++;
        }
        p=0;
        for(l=0;l<j;l++)
        {
          p=p*10+c[l];
        }
        q=0;
        for(l=0;l<k;l++)
        {
          q=q*10+d[l];
        }
        result=p+q;
        n=0;
        while(result!=0)
        {
            e[n]=result%10;
            result=result/10;
            n++;
        }
        r=0;
         for(l=0;l<n;l++)
        {
          r=r*10+e[l];
        }
       printf("%lld\n",r);

    }

}
