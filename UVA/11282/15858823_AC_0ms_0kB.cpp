#include<bits/stdc++.h>
using namespace std;
long long ncr[25][25];
long long dr[30];

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

long long darngmnt(long long n)
{
    if(n==0){
        return 1;
    }
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dr[n]!=-1){
        return dr[n];
    }
    return dr[n]=(n-1)*(darngmnt(n-2)+darngmnt(n-1));
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        memset(ncr,-1,sizeof ncr);
        memset(dr,-1,sizeof dr);
        long long ans=darngmnt(n);
        for(long long i=1;i<=m;i++){
            ans+=nCr(n,i)*darngmnt(n-i);
        }
        cout<<ans<<endl;
    }
}