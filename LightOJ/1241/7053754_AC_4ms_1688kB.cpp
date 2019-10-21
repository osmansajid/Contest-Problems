#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,j;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        int n,i,k=2,count=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            if(a[i]>k)
            {
                count+=ceil((a[i]-k)/5.0);
                k=a[i];
            }
        }
        printf("Case %d: %d\n",j,count);
    }
}
