#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long ncr[1000][1000];
long long nCr(long long n,long long r)
{
    if(r==1){
        return n;
    }
    if(r==n){
        return 1;
    }
    if(ncr[n][r]==-1){
        ncr[n][r]=nCr(n-1,r-1) + nCr(n-1,r);
    }
    return ncr[n][r];
}

int main()
{
    memset(ncr,-1,sizeof ncr);
    ll n;
    cin>>n;
    ll ans=nCr(n,5)+nCr(n,6)+nCr(n,7);
    cout<<ans<<endl;
}
