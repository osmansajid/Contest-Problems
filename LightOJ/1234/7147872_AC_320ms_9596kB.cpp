#include<bits/stdc++.h>
using namespace  std;
#define delta 0.57721566490153286060651209
double a[1000000];
int main()
{
    double r;
    long long i,n,t;
    a[0]=0.0;
    for(i=1;i<=1000000;i++)
    {
        a[i]=a[i-1]+((double)1.0/i);
    }
    cin>>t;
    for(i=1;i<=t;i++)
    {
     cin>>n;
     if(n<=1000000)
     {
         printf("Case %lld: %.10lf\n",i,a[n]);
     }
     else
     {
         r=log(n+0.5)+delta;
         printf("Case %lld: %.10lf\n",i,r);
     }
    }
}
