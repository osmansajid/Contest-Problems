#include<bits/stdc++.h>
using namespace std;
#define MAX 999999999
int dp[1010][22][80],ox[1010],ni[1010],W[1010],m,n,o;

int call(int i,int wo,int wn)
{
    if(i>=m){
        if(wo>=o && wn>=n){
            return 0;
        }
        return MAX;
    }
    if(wo>=o && wn>=n){
        return 0;
    }
    if(dp[i][wo][wn]!=-1){
        return dp[i][wo][wn];
    }
    int res1=MAX,res2=MAX;
    res1=W[i]+call(i+1,min(wo+ox[i],o),min(wn+ni[i],n));
    res2=call(i+1,wo,wn);
    return dp[i][wo][wn]=min(res1,res2);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin>>o>>n>>m;
        for(int i=0 ;i<m;i++){
            cin>>ox[i]>>ni[i]>>W[i];
        }
        cout<<call(0,0,0)<<endl;
    }
}
