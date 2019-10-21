#include<bits/stdc++.h>
using namespace std;
int dp[52][1010],v[52],w[52],n,k;

int call(int i,int W){
    if(i>=n){
        return 0;
    }
    if(dp[i][W]!=-1){
        return dp[i][W];
    }
    int res1=0,res2=0;
    if(W+w[i]<=k){
        res1=v[i]+call(i+1,W+w[i]);
    }
    res2=call(i+1,W);
    return dp[i][W]=max(res1,res2);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin>>k>>n;
        for(int i=0;i<n;i++){
            cin>>w[i]>>v[i];
        }
        cout<<"Hey stupid robber, you can get "<<call(0,0)<<"."<<endl;
    }
}
