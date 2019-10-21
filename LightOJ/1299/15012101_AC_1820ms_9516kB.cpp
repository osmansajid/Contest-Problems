#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
string s;
long long dp[1001][1001];

long long call(int indx,long long emp){
    if(indx>=s.size()){
        if(emp==0) return 1;
        else return 0;
    }
    if(dp[indx][emp]!=-1) return dp[indx][emp];
    long long ret=1;
    if(s[indx]=='U'){
        //ret=((ret%mod)*(call(indx+1,emp+1)%mod+((emp%mod)*(call(indx+1,emp)%mod))%mod)%mod)%mod;
        ret=(call(indx+1,emp+1)%mod+((emp%mod)*(call(indx+1,emp)%mod))%mod)%mod;
    }
    else if(s[indx]=='D'){
        //ret=((ret%mod)*(((emp%mod)*(call(indx+1,emp)%mod))%mod+((emp%mod)*(emp%mod)*(call(indx+1,emp-1)%mod))%mod)%mod)%mod;
        ret=(((emp%mod)*(call(indx+1,emp)%mod))%mod+((emp%mod)*(emp%mod)*(call(indx+1,emp-1)%mod))%mod)%mod;
    }
    else{
        ret=call(indx+1,emp)%mod;
    }
    return dp[indx][emp]=ret;
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        cin>>s;
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<++tc<<": "<<call(0,0)<<endl;
    }
}
