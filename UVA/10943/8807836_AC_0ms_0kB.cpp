#include<bits/stdc++.h>
#define mod 1000000
using namespace std;
long long dp[210][210];
int n,k,a[210];

long long call(int make,int kk)
{
    if(kk==0){
        if(make==0) return 1;

        else return 0;
    }
    if(dp[make][kk]!=-1){
        return dp[make][kk];
    }
    long long res1=0;
    for(int i = 0; i <= n; ++i)
       if(make-a[i]>=0) res1=(res1%mod+call(make-a[i],kk-1)%mod)%mod;
    return dp[make][kk]=(res1)%mod;
}
int main()
{
    for(int i=0;i<=100;i++){
        a[i]=i;
    }
    memset(dp,-1,sizeof dp);
    while(scanf("%d %d",&n,&k)){
        if(n==0 && k==0) break;
        printf("%lld\n",(call(n,k)%mod));
    }
}
