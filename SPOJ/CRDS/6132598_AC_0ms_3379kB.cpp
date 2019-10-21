#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,a,i,p;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&a);
        p=((a*(3*a+1))/2)%1000007;
        printf("%lld\n",p);
    }
}
