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
    long long a,b;
    while(cin>>a>>b)
    {
        long long g,l,p,q;
       // printf("%d %d\n",a,b);
        p=a;
        q=b;
        g=gcd(a,b);
        l=(p/g)*q;
        printf("%lld %lld\n",g,l);
    }
}
