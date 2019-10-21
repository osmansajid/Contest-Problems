#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[110][110];

int LCS(int i,int j)
{
    if(i==a.size()|| j==b.size()){
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
    int tc=0;
    while(getline(cin,a)){
        if(a[0]=='#') break;
        memset(dp,-1,sizeof dp);
        getline(cin,b);
        cout<<"Case #"<<++tc<<": you can visit at most "<<LCS(0,0)<<" cities."<<endl;
    }
}
