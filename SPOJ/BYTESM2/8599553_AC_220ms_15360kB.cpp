#include<bits/stdc++.h>
using namespace std;
int dp[110][110];
int a[110][110],n,m;
int fun(int i, int j)
{
    if(i<0 || j<0 || i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res1=0,res2=0,res3=0;
    res1=a[i][j]+fun(i+1,j);
    res2=a[i][j]+fun(i+1,j-1);
    res3=a[i][j]+fun(i+1,j+1);
    return dp[i][j]=max(res1,max(res2,res3));
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            memset(dp,-1,sizeof dp);
            ans=max(ans,fun(0,i));
        }
        cout<<ans<<endl;
    }
}
