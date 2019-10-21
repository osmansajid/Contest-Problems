#include<bits/stdc++.h>
using namespace std;
long long bell[100];
long long ncr[100][100];

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
        int y= ((nCr(n,i)) *(o_bell(n-i)));
        bell[n]=((bell[n]) + (y));
    }
 }
 return bell[n];
}

int main()
{
    int t;
    memset(ncr,-1,sizeof ncr);
    memset(bell,0,sizeof bell);
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        cout<<o_bell(n)<<endl;
    }
}
