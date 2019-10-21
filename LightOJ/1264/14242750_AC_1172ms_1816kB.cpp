#include<bits/stdc++.h>
using namespace std;

int Set(int mask,int pos){
    return mask=mask|(1<<pos);
}
int reset(int mask,int pos){
    return mask=mask&~(1<<pos);
}
bool check(int mask,int pos){
    return (bool)(mask&(1<<pos));
}
int dp[(1<<14)+2],val[(1<<14)+2];

int call(int mask)
{
    if(mask==0) return 0;
    if(dp[mask]!=-1) return dp[mask];
    int ret=0;
    for(int sub=mask;sub>0;sub=(sub-1)&mask){
        if(val[sub]<0)ret=min(ret,call(mask^sub)+val[sub]);
    }
    return dp[mask]=ret;
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[n][n];
        memset(dp,-1,sizeof dp);
        memset(val,0,sizeof val);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int mask=(1<<n)-1;
        int ans=INT_MAX;
        for(int sub=mask;sub>0;sub=(sub-1)&mask){
            for(int i=0;i<n;i++){
                if(check(sub,i)==true){
                    for(int j=0;j<n;j++){
                        if(check(sub,j)==true){
                            val[sub]+=a[i][j];
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n",++tc,call(mask));
    }
}
