#include<bits/stdc++.h>
using namespace std;
long long dp[10010];

long long fun(int indx,int n,int a[])
{
    if(indx>=n){
        return 0;
    }
    if(dp[indx]!=-1){
        return dp[indx];
    }
    long long p1=0;
    long long p2=0;
    p1= a[indx]+fun(indx+2,n,a);
    p2=fun(indx+1,n,a);
    return dp[indx]=max(p1,p2);
}

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        printf("Case %d: %lld\n",++tc,fun(0,n,a));
    }
}
