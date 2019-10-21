#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int cost[1010],weight[1010],s,n;
int knapsack(int i,int w)
{
    if(i>n) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    int profit1=0,profit2=0;
    if(w+weight[i]<=s) profit1=cost[i]+knapsack(i+1,w+weight[i]);
    profit2=knapsack(i+1,w);
    dp[i][w]=max(profit1,profit2);
    return dp[i][w];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(cost,0,sizeof cost);
        memset(weight,0,sizeof weight);
        for(int i=1;i<=n;i++)
        {
            cin>>cost[i]>>weight[i];
        }
        int p,ans=0;
        cin>>p;
        for(int i=0;i<p;i++)
        {
            memset(dp,-1,sizeof dp);
            cin>>s;
            ans+=knapsack(1,0);
        }
        cout<<ans<<endl;
    }
}

