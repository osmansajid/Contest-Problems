#include<bits/stdc++.h>
using namespace std;
string s;
long long dp[71][71];

bool check(int l,int i,int j){
    if((s[l]=='R' && s[i]=='R') || (s[l]=='R' && s[j]=='R') || (s[i]=='R' && s[j]=='R')) return false;
    return true;
}

long long call(int l,int r){
    if(r<l) return 1;
    if(dp[l][r]!=-1) return dp[l][r];
    long long ret=0;
    for(int i=l+1;i<=r;i+=3){
        for(int j=i+1;j<=r;j+=3){
            if(check(l,i,j))ret+=call(l+1,i-1)*call(i+1,j-1)*call(j+1,r);
        }
    }
    return dp[l][r]=ret;
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        cin>>s;
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<++tc<<": "<<call(0,s.size()-1)<<endl;
    }
}
