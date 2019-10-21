#include<bits/stdc++.h>
using namespace std;
int n,m,a[11],dp[11][11];

int call(int indx,int cur)
{
    if(indx>=m){
        return 1;
    }
    if(dp[indx][cur]!=-1) return dp[indx][cur];
    int res=0;
    for(int i=0;i<n;i++){
        if(abs(cur-a[i])<=2){
            //cout<<cur<<a[i]<<endl;
            res+=call(indx+1,a[i]);
        }
    }
    return dp[indx][cur]=res;
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n>>m;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            ans+=call(1,a[i]);
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
}
