#include<bits/stdc++.h>
#define mod 10056
using namespace std;

long long ncr[1001][1001];
long long bell[1001];

long long nCr(long long n,long long r)
{
    if(r==1){
        return n;
    }
    if(r==n){
        return 1;
    }
    if(ncr[n][r]==-1){
        ncr[n][r]=(nCr(n-1,r-1)%mod + nCr(n-1,r)%mod)%mod;
    }
    return ncr[n][r]%mod;
}

long long o_bell(long long n){
 if(n==0){
    return 1;
 }
 if(n==1){
    return 1;
 }
 if( bell[n]!= 0){
    return bell[n];
 }
 else{
    for(int i=1;i<=n;i++){
        int y= ((nCr(n,i)%mod) *(o_bell(n-i)%mod))%mod;
        bell[n]=((bell[n]%mod) + (y%mod))%mod;
    }
 }
 return bell[n];
}

int main()
{
    //freopen("input.txt","r",stdin);
    int t,tc=0;
    memset(ncr,-1,sizeof ncr);
    memset(bell,0,sizeof bell);
    cin>>t;
    while(t--){
        long long s;
        cin>>s;
        cout<<"Case "<<++tc<<": "<<o_bell(s)<<endl;
    }
}
