#include<bits/stdc++.h>
using namespace std;
int s,n;
int dp[2010][2010];
int weight[2010],cost[2010];
int knapsack(int i,int w)
{
    if(i>n) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    int profit1=0,profit2=0;
    if(w+weight[i]<=s)
    {
        profit1=cost[i]+knapsack(i+1,w+weight[i]);
    }
    profit2=knapsack(i+1,w);
    dp[i][w]= max(profit1,profit2);
    return dp[i][w];
}
int main()
{
    memset(dp,-1,sizeof dp);
    scanf("%d %d",&s,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&weight[i],&cost[i]);
    }
    cout<<knapsack(1,0)<<endl;
}
