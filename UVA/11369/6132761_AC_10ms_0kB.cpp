#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,i,j,p,k;
    long long a[20005];
    long long b[20005];
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&a[j]);
        }
        sort(a,a+n);
        for(j=n-1,k=0;j>=0;j--,k++)
        {
            b[k]=a[j];
        }
        p=0;
        for(j=2;j<n;j=j+3)
        {
            p=p+b[j];
        }
        printf("%lld\n",p);
    }
}
