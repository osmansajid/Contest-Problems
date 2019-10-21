#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[2010][2010];

int LVD(int i,int j)
{
    int cost;
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res1=0,res2=0,res3=0,res4=0;
    if(a[i]!=b[j]){
        cost=1;
    }
    else{
        cost=0;
    }
    res1=1+LVD(i,j-1);
    res2=1+LVD(i-1,j);
    res3=cost+LVD(i-1,j-1);
    res4=min(min(res1,res2),res3);
    return dp[i][j]=res4;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin>>a>>b;
        int p=LVD(a.size()-1,b.size()-1);
        cout<<p<<endl;
    }
}
