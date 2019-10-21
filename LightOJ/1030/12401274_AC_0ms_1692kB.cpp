#include<bits/stdc++.h>
using namespace std;
double dp[110],a[110];;
int n;

double call(int indx){
    if(indx>n) return 0.0;
    if(dp[indx]!=0.0) return dp[indx];
    double res=a[indx];
    for(int i=indx+1;i<=n && i<=(indx+6);i++){
        res+=(double)(1.0/min(6.0,(double)(n-indx)))*call(i);
    }
    return dp[indx]=res;
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(dp,0.0,sizeof dp);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lf",&a[i]);
        }
        printf("Case %d: %.10lf\n",++tc,call(1));
    }
}
