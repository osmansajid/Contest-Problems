#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int dp[60][60][60];

int LCS(int i,int j,int k)
{
    if(i==a.size() || j==b.size() || k==c.size()){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    int res1=0,res2=0,res3=0;
    if(a[i]!=b[j] && a[i]!=c[k]){
        res1=LCS(i,j+1,k+1);
        res2=LCS(i+1,j,k);
        res3=max(res1,res2);
    }
    else if(b[j]!=a[i] && b[j]!=c[k]){
        res1=LCS(i+1,j,k+1);
        res2=LCS(i,j+1,k);
        res3=max(res1,res2);
    }
    else if(c[k]!=a[i] && c[k]!=a[i]){
        res1=LCS(i+1,j+1,k);
        res2=LCS(i,j,k+1);
        res3=max(res1,res2);
    }
    else{
        res3=1+LCS(i+1,j+1,k+1);
    }
    return dp[i][j][k]=res3;
}

int main()
{
    int t,tc=0;
    //freopen("a.txt","r",stdin);
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin>>a>>b>>c;
        cout<<"Case "<<++tc<<": "<<LCS(0,0,0)<<endl;
    }
}
