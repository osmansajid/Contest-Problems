#include<bits/stdc++.h>
using namespace std;
long long dp[100000];

int call(int n,int m){
    if(n<0 || dp[n]==-2){
        return 1000000;
    }
    if(n==m){
        return dp[n]=1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    long long res1=0,res2=0,res3=0;
    dp[n]=-2;
    if(n<m){
        res1=1+call(n*2,m);
        res2=1+call(n-1,m);
        res3=min(res1,res2);
    }
    else{
        res3=1+call(n-1,m);
    }
    return dp[n]=res3;
}

int main()
{
    memset(dp,-1,sizeof dp);
    int n,m;
    cin>>n>>m;
    cout<<call(n,m)-1<<endl;
}
