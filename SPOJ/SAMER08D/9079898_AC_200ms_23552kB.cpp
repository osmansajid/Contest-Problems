#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int seg[1010][1010];
int n;

void LCS(string a,string b)
{
    memset(dp,0,sizeof dp);
    memset(seg,0,sizeof seg);
    for(int i=0;i<=a.size();i++){
        for(int j=0;j<=b.size();j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                seg[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                seg[i][j]=seg[i-1][j-1]+1;
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            else{
                seg[i][j]=0;
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            //cout<<dp[i][j]<<" ";
            if(seg[i][j]>=n){
               for(int k=n;k<=seg[i][j];k++) dp[i][j]=max(dp[i][j],dp[i-k][j-k]+k);
            }
        }
       // cout<<endl;
    }
    cout<< dp[a.size()][b.size()]<<endl;
}
int main()
{
    while(cin>>n){
        if(n==0){
            break;
        }
        string a,b;
        cin>>a>>b;
        LCS(a,b);
    }
}

