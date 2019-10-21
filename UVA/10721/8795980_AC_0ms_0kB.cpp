#include<bits/stdc++.h>
using namespace std;
long long dp[51][51];
int l,m,n,a[51];

long long call(int indx,int make)
{
    if(indx>m){
        if(make==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[indx][make]!=-1) return dp[indx][make];
    long long res1=0;
    for(int i=1;i<=n;i++){
        if(make-a[indx]*i>=0){
            res1+= call(indx+1,make-a[indx]*i);
        }
    }
    return dp[indx][make]=res1;
}
int main()
{
    for(int i=1;i<=50;i++){
        a[i]=1;
    }
    while(cin>>l>>m>>n){
        memset(dp,-1,sizeof dp);
        cout<<call(1,l)<<endl;
    }
}
