#include<bits/stdc++.h>
using namespace std;
int dp[55][1010];
int n,k,c[1010],w[1010];

int call(int i,int W)
{
    if(i>=n){
        return 0;
    }
    if(dp[i][W]!=-1){
        return dp[i][W];
    }
    int res1=0,res2=0;
    if(W+w[i]<=k){
        res1=c[i]+call(i+1,W+w[i]);
    }
    res2=call(i+1,W);
    return dp[i][W]=max(res1,res2);
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d",&k,&n);
       memset(dp,-1,sizeof dp);
       for(int i=0;i<n;i++){
            scanf("%d %d",&w[i],&c[i]);
       }
       int ans=call(0,0);
       printf("Hey stupid robber, you can get %d.\n",ans);
    }
}
