#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k,ans;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        a[i]=a[i]+a[i-1];
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>k;
        int start=0;
        int finish=n-1;
        while(start<=finish)
        {
            int mid=(start+finish)/2;
            if(start==finish)
            {
                ans=start;
                break;
            }
            else if(k>a[mid])
            {
                start=mid+1;
            }
            else if(k<=a[mid])
            {
                finish=mid;
            }
        }
        cout<<ans+1<<endl;
    }
}
