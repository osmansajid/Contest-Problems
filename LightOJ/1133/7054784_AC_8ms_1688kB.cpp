#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,j;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        int n,m,i,k;
        char c;
        cin>>n>>m;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<m;i++)
        {
            cin>>c;
            if(c=='S')
            {
                int d;
                cin>>d;
                for(k=0;k<n;k++)
                {
                    a[k]=a[k]+d;
                }
            }
            else if(c=='M')
            {
                int d;
                cin>>d;
                for(k=0;k<n;k++)
                {
                    a[k]=a[k]*d;
                }
            }
            else if(c=='D')
            {
                int d;
                cin>>d;
                for(k=0;k<n;k++)
                {
                    a[k]=a[k]/d;
                }
            }
            else if(c=='R')
            {
                reverse(a,a+n);
            }
            else if(c=='P')
            {
                int w,x;
                cin>>w>>x;
                swap(a[w],a[x]);
            }
        }
        printf("Case %d:\n",j);
        for(i=0;i<n;i++)
        {
            if(i!=n-1)
            {
                printf("%d ",a[i]);
            }
            else
            {
                printf("%d",a[i]);
            }
        }
        printf("\n");
    }
}
