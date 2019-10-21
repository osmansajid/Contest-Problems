#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[110][110];

int LCS(int i,int j)
{
    if(i==a.size() || j==b.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res1=0,res2=0,res3=0;
    if(a[i]!=b[j]){
        res1=LCS(i,j+1);
        res2=LCS(i+1,j);
        res3=max(res1,res2);
    }
    else{
        res3=1+LCS(i+1,j+1);
    }
    return dp[i][j]=res3;
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    string c;
    while(t--){
        cin>>c;
        memset(dp,-1,sizeof dp);
        a=c;
        reverse(c.begin(),c.end());
        b=c;
        int p=LCS(0,0);
        printf("Case %d: %d\n",++tc,c.size()-p);
    }
}

