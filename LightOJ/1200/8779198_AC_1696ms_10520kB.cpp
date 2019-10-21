#include<bits/stdc++.h>
using namespace std;
long long dp[110][10010];
int n,m,p[110],w[110],c[110];

long long call(int indx,int W)
{
    if(indx>=n) return 0;
    if(dp[indx][W]!=-1) return dp[indx][W];
    long long res1=0,res2=0;
    if(W+w[indx]<=m){
       res1=p[indx]+call(indx,W+w[indx]);
    }
    res2=call(indx+1,W);
    return dp[indx][W]=max(res1,res2);
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof dp);
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&p[i],&c[i],&w[i]);
        }
        for(int i=0;i<n;i++){
            m-=c[i]*w[i];
        }
        printf("Case %d: ",++tc);
        if(m<0) cout<<"Impossible"<<endl;
        else cout<<call(0,0)<<endl;
    }
}
