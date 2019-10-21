#include<bits/stdc++.h>
using namespace std;
bool  check(int n,int a[],int mid)
{
    for(int i=1;i<=n;i++){
        if(a[i]-a[i-1]>mid){
            return 0;
        }
        else if(a[i]-a[i-1]==mid){
            mid--;
        }
    }
    return 1;
}
int main()
{
    int t,tc=0;
    //freopen("input.txt","r",stdin);
    cin>>t;
    while(t--){
        int n,maxx=0;
        cin>>n;
        int a[n+7],b[n+7];
        a[0]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int low=0,high=a[n],mid,ans;
        while(low<=high){
            mid=(low+high)/2;
            if(check(n,a,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
}
