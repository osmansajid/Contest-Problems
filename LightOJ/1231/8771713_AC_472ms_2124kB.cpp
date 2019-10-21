#include<bits/stdc++.h>
#define mod 100000007
using namespace std;
long long dp[55][1010];
int n,k,a[55],c[55];

int call(int indx,int make)
{
    if(indx>=n){
        if(make==0){
            return 1;
        }
        else return 0;
    }
    if(dp[indx][make]!=-1) return dp[indx][make];
    long long res1=0,res2=0;
    for(int i=1;i<=c[indx];i++){
        if(make-a[indx]*i>=0){
            res1=(res1%mod + call(indx+1,make-a[indx]*i)%mod)%mod;
        }
    }
    res2=call(indx+1,make)%mod;
    return dp[indx][make]=(res1%mod + res2%mod)%mod;
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof dp);
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&c[i]);
        }
        cout<<"Case "<<++tc<<": "<<call(0,k)%mod<<endl;
    }
}
