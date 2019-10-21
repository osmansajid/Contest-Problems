#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,tc=0;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n+10];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int p,mid,f=0,ans1,ans2,mini=INT_MAX;
        cin>>p;
        for(i=0;i<n;i++)
        {
            if(a[i]<p)
            {
                int low=i+1;
                int high=n-1;
                while(low<=high)
                {
                    mid=(low+high)/2;
                    if(a[i]+a[mid]==p)
                    {
                        if(abs(a[i]-a[mid])<mini){
                            ans1=a[i];
                            ans2=a[mid];
                            mini=abs(a[i]-a[mid]);
                        }
                        break;
                    }
                    else if(a[i]+a[mid]<p)
                    {
                        low=mid+1;
                    }
                    else if(a[i]+a[mid]>p)
                    {
                        high=mid-1;
                    }
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",ans1,ans2);
    }

}
