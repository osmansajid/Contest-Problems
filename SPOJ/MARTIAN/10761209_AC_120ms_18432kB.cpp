#include<bits/stdc++.h>
using namespace std;
int dp[501][501],a[501][501],b[501][501];

int call(int i,int j){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=max(a[i][j]+call(i-1,j),b[i][j]+call(i,j-1));
}
int main()
{
    int t,tc=0,n,m;
    //scanf("%d",&t);
    while(scanf("%d %d",&n,&m)){
        if(n==0 && m==0) break;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&a[i][j]);
                if(j!=0)a[i][j]+=a[i][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&b[i][j]);
                if(i!=0)b[i][j]+=b[i-1][j];
            }
        }
        printf("%d\n",call(n-1,m-1));
    }
}
