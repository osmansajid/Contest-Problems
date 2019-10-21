#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
pii dp[101][101];

pii mcm(int a[],int i,int j){
    if(i==j){
        return make_pair(a[i],0);
    }
    if(dp[i][j].first!=-1){
        return dp[i][j];
    }
    pii ret1,ret2,ret3,mini;
    mini=make_pair(0,INT_MAX);
    for(int k=i;k<j;k++){
        ret1=mcm(a,i,k);
        ret2=mcm(a,k+1,j);
        ret3=make_pair((ret1.first+ret2.first)%100,(ret1.first*ret2.first)+ret1.second+ret2.second);
        if(ret3.second<mini.second){
            mini=ret3;
        }
    }
    return dp[i][j]=mini;
}

int main()
{
   int n;
   while(scanf("%d",&n)==1){
        memset(dp,-1,sizeof dp);
        int a[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        printf("%d\n",mcm(a,0,n-1).second);
   }
}
