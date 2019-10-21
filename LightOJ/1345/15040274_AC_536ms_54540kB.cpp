#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int m,k;
int dp[51][51][51][2][51];

int call(int n,int last,int inc,int fl,int k){

    //cout<<endl<<" "<<n<<" "<<last<<" "<<inc<<" "<<fl<<endl;
    if(n==0){
        if(fl==1) return 1;
        else return 0;
    }
    if(dp[n][last][inc][fl][k]!=-1) return dp[n][last][inc][fl][k];
    int ret=0;
    for(int i=1;i<=last-1;i++){
        //cout<<i<<" ";
        ret=(ret%mod + call(n-1,i,1,fl|(inc==k),k)%mod)%mod;
    }
    //cout<<endl;
    if(inc<k){
        for(int i=last+1;i<=n+1;i++){
        //  cout<<i<<" ";
            ret=(ret%mod+call(n-1,i-1,inc+1,fl|(inc+1==k),k)%mod)%mod;
        }
    }
    //cout<<endl;
    return dp[n][last][inc][fl][k]=ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=t;i++){
        scanf("%d %d",&m,&k);
        int ans=0;
        for(int j=1;j<=m;j++){
            ans=(ans%mod+call(m-1,j,1,0|k==1,k)%mod)%mod;
        }
        printf("Case %d: %lld\n",i,ans%mod);
    }
}
