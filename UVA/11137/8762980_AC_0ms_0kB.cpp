#include<bits/stdc++.h>
using namespace std;
long long dp[22][10010];
int c[]={1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};

long long coin_chng(int i,int n)
{
    if(i>=21){
        if(n==0){
            return 1;
        }
        else return 0;
    }
    if(dp[i][n]!=-1){
        return dp[i][n];
    }
    long long res1=0,res2=0;
    if(n-c[i]>=0){
        res1=coin_chng(i,n-c[i]);
    }
    res2=coin_chng(i+1,n);
    return dp[i][n]=res1+res2;
}
int main()
{
    int n;
    memset(dp,-1,sizeof dp);
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",coin_chng(0,n));
    }
}
