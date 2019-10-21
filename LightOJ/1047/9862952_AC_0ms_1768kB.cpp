#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int r[100][100],n;
int call(int i,int j)
{
    if(i>=n){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int res1=999999999,res2=999999999,res3=999999999;
    if(j==0)res1=r[i][j]+min(call(i+1,j+1),call(i+1,j+2));
    if(j==1)res2=r[i][j]+min(call(i+1,j-1),call(i+1,j+1));
    if(j==2)res3=r[i][j]+min(call(i+1,j-2),call(i+1,j-1));
    return dp[i][j]=min(min(res1,res2),res3);
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                scanf("%d",&r[i][j]);
            }
        }
        int ans=999999999;
        for(int i=0;i<3;i++){
            ans=min(ans,call(0,i));
        }
        printf("Case %d: %d\n",++tc,ans);
    }
}