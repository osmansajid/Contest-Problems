#include<bits/stdc++.h>
using namespace std;
int n,m,dp[11][11],a[11];

int call(int i,int k)
{
     if(k==0){
        return 1;
     }
     if(dp[i][k]!=-1){
        return dp[i][k];
     }
     int res1=0,res2=0;
     for(int j=0;j<n;j++){
        if(abs(a[j]-a[i])<=2){
            res1+=call(j,k-1);
        }
     }
     return dp[i][k]=res1;
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        int ans=0;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++) ans+=call(i,m-1);
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
}
