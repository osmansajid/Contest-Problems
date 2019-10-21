#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],n,m;
bool check(long long k){
    long long x=0;
    for(int i=0;i<n;i++){
        if(a[i]*k>b[i]){
            x+=((a[i]*k)-b[i]);
        }
        if(x>m) return false;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    long long low=0,high=2000000000,mid,ans;
    while(low<=high){
        mid=(low+high)/2;
        if(check(mid)==1){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;
}