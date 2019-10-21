#include<bits/stdc++.h>
using namespace std;
long long dp[40][40],a[40],n;

long long call(int i,int m){
    if(i>2*n){
        if(m==0) return 1;
        return 0;
    }
    if(dp[i][m]!=-1) return dp[i][m];
    long long res1=0,res2=0;
    if(a[i]){
        res1=call(i+1,m+1);
    }
    else{
        res1=call(i+1,m+1);
        if(m>0)res2=call(i+1,m-1);
    }
    return dp[i][m]=res1+res2;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        memset(a,0,sizeof a);
        long long k,x;
        cin>>n>>k;
        for(int i=0;i<k;i++){
            cin>>x;
            a[x]=1;
        }
        cout<<call(1,0)<<endl;
    }
}
