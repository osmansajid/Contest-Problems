#include<bits/stdc++.h>
using namespace std;
int dp[1010],a[1010],n;

int fun(int indx)
{
    if(indx>=n-1){
        return 0;
    }
    if(dp[indx]!=-1){
        return dp[indx];
    }
    int res1=0,res2=0;
    res1=a[indx]+fun(indx+2);
    res2=fun(indx+1);
    return dp[indx]=max(res1,res2);
}

int fun2(int indx)
{
    if(indx>=n){
        return 0;
    }
    if(dp[indx]!=-1){
        return dp[indx];
    }
    int res1=0,res2=0;
    res1=a[indx]+fun2(indx+2);
    res2=fun2(indx+1);
    return dp[indx]=max(res1,res2);
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof dp);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int ans1=fun(0);
        memset(dp,-1,sizeof dp);
        int ans2=fun2(1);
        cout<<"Case "<<++tc<<": "<<max(ans1,ans2)<<endl;
    }
}
