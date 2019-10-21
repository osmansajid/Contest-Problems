#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    while(b!=0)
    {
        a=a%b;
        swap(a,b);
    }
    return a;
}
int main()
{
    long long t,i,j,x,y;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        long long n,l=1,s,m=0,p=0;
        cin>>n;
        long long a[n+4];
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            l=l*a[i];
        }
        for(i=1;i<=n;i++)
        {
            m+=(l/a[i]);
        }
        s=n*l;
        x=s;
        y=m;
        while(p!=1)
        {
            p=gcd(x,y);
            x=x/p;
            y=y/p;
        }
        printf("Case %lld: %lld/%lld\n",j,x,y);
    }
}
