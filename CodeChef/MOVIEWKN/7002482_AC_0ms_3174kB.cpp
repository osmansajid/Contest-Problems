#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,ans=0,max=0,r;
        cin>>n;
        int a[n],b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
            if(b[i]*a[i]>max )
            {
                max=b[i]*a[i];
                ans=i;
                r=b[i];
            }
            else if(b[i]*a[i]==max)
            {
                if(b[i]>r)
                {
                    max=b[i]*a[i];
                    ans=i;
                    r=b[i];
                }
                else if(b[i]<r)
                {

                }
                else
                {

                }
            }
        }
        cout<<ans+1<<endl;

    }
}
