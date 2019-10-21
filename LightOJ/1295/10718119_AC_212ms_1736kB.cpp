#include<bits/stdc++.h>
#define MAX 999999999999999999
using namespace std;
long long dp[1010],n,sum[1010];

struct volt{
    long long v,vc,lc,l;
}a[1010];;

bool operator< (volt A,volt B)
{
    return A.v<B.v;
}
long long call(int i)
{
    if(i==0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    volt cur=a[i];
    long long res1=MAX,res2=MAX;
    for(int j=0;j<i;j++){
        res2=cur.vc+cur.lc*(sum[i]-sum[j])+call(j);
        res1=min(res1,res2);
    }
    return dp[i]=res1;
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof dp);
        memset(sum,0,sizeof sum);
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld %lld %lld %lld",&a[i].v,&a[i].vc,&a[i].lc,&a[i].l);
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) sum[i]+=sum[i-1]+a[i].l;
        printf("Case %d: %lld\n",++tc,call(n));
        //for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    }
}
