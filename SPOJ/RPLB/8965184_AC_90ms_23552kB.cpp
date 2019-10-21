#include<bits/stdc++.h>
using namespace std;
long long dp[1010][1010];
int n,m,a[1010];

long long call(int indx,int w){
    if(indx>=n){
        return 0;
    }
    if(dp[indx][w]!=-1) return dp[indx][w];
    long long res1=0,res2=0;
    if(w+a[indx]<=m){
        res1=a[indx]+call(indx+2,w+a[indx]);
    }
    res2=call(indx+1,w);
    return dp[indx][w]=max(res1,res2);
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof dp);
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        printf("Scenario #%d: %lld\n",++tc,call(0,0));
    }
}
