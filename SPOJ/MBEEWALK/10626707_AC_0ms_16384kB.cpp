#include<bits/stdc++.h>
using namespace std;
int dp[100][100][20],n;

long long call(int i,int j,int step){
    if(step==n){
        if(i==n && j==n){
            return 1;
        }
        return 0;
    }
    if(dp[i][j][step]!=-1) return dp[i][j][step];
    int res1=0,res2=0,res3=0,res4=0,res5=0,res6=0;
    if(i%2==0)res1=call(i-1,j-1,step+1);
    else res1=call(i-1,j+1,step+1);
    res2=call(i-1,j,step+1);
    res3=call(i,j+1,step+1);
    res4=call(i+1,j,step+1);
    if(i%2==0)res5=call(i+1,j-1,step+1);
    else res5=call(i+1,j+1,step+1);
    res6=call(i,j-1,step+1);
    return dp[i][j][step]=res1+res2+res3+res4+res5+res6;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin>>n;
        cout<<call(n,n,0)<<endl;
    }
}
