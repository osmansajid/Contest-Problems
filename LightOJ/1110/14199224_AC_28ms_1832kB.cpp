#include<bits/stdc++.h>
using namespace std;
int dp[110][110];
string dr[110][110];

void LCS(string a,string b)
{
    memset(dp,0,sizeof dp);
    memset(dp,0,sizeof dp);
    for(int i=0;i<=a.size();i++){
        for(int j=0;j<=b.size();j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                dr[i][j]=dr[i-1][j-1]+a[i-1];
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    dr[i][j]=dr[i-1][j];
                }
                else if(dp[i-1][j]<dp[i][j-1]){
                    dp[i][j]=dp[i][j-1];
                    dr[i][j]=dr[i][j-1];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                    dr[i][j]=min(dr[i-1][j],dr[i][j-1]);
                }
            }
        }
    }
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        LCS(a,b);
        if(dp[a.size()][b.size()]==0){
            cout<<"Case "<<++tc<<": "<<":("<<endl;
        }
        else{
            cout<<"Case "<<++tc<<": "<<dr[a.size()][b.size()]<<endl;
        }
    }
}
