#include<bits/stdc++.h>
using namespace std;
map<long long, map<long long,long long> > dp;
int n;
long long func(int i,int j)
{
    if(i==2*n) return dp[i][j];
    else return max(dp[i][j]+func(i+1,j),dp[i][j]+func(i+1,j+1));
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int k=2;
        for(int i=1;i<2*n;i++)
        {
          if(i<=n)
          {
              for(int j=1;j<=i;j++)
              {
                cin>>dp[i][j];
              }
          }
          else
          {
              for(int j=1;j<k;j++) dp[i][j]=0;
              for(int j=k;j<k+2*n-i;j++) cin>>dp[i][j];
              for(int j=k+2*n-i;j<=i;j++) dp[i][j]=0;
              k++;
          }
        }
        for(int i=2*n-2;i>=1;i--)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=max(dp[i][j]+dp[i+1][j],dp[i][j]+dp[i+1][j+1]);
            }
        }
       cout<<"Case "<<++tc<<": "<<dp[1][1]<<endl;
       dp.clear();
    }
}
