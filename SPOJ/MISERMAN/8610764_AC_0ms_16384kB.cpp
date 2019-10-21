#include<bits/stdc++.h>
using namespace std;
int dp[110][110],a[110][110],n,m;

int fun(int i,int j)
{
    if(i>n){
        return 0;
    }
    if(j<0 || j>=m){
        return 1000000;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res1=1000000,res2=1000000,res3=1000000;
    res1=a[i][j]+fun(i+1,j);
    res2=a[i][j]+fun(i+1,j-1);
    res3=a[i][j]+fun(i+1,j+1);
    return dp[i][j]=min(res1,min(res2,res3));
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int ans=1000000;
    for(int i=0;i<m;i++){
        memset(dp,-1,sizeof dp);
        ans=min(ans,fun(0,i));
    }
    cout<<ans<<endl;
}
