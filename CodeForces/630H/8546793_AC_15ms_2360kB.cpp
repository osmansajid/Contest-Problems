#include<bits/stdc++.h>
using namespace std;
long long ncr[200][200];
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
    long long n,ans;
    cin>>n;
    ans=nCr(n,5)*n*(n-1)*(n-2)*(n-3)*(n-4);
    cout<<ans;
}
