#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,i,n;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        long long a[n],ans,j,k,p;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        long long r=abs(a[1]-a[0]);
        for(j=0;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                p=abs(a[j]-a[k]);
                if(p<r)
                {
                    r=p;
                }
            }
        }
        printf("%lld\n",r);
    }
}
