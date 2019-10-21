#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001];

int check(int x){
    int ans=0,ans2=INT_MAX;
    for(int i=1;i<=n-x+1;i++){
        ans=a[i+x-1]-a[i-1];
        ans2=min(ans2,ans);
    }
    return ans2;
}

int main()
{
    cin>>n>>m;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    int hi=m,lo=0,mid,ok;
    while(lo<hi){
        mid=(lo+hi+1)/2;
        ok=check(mid);
        //cout<<ok<<" "<<mid<<endl;
        if(ok>m){
            hi=mid-1;
        }
        else{
            lo=mid;
        }
    }
    cout<<hi<<endl;
    //main();
}
