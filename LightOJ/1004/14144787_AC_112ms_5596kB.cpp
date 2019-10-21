#include<bits/stdc++.h>
using namespace std;
long long n,a[500][500],dp[500][500];
long long call(int i,int j){
    if(i>=2*n-1 || j>=n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    long long res1=0,res2=0;
    res1+=a[i][j]+call(i+1,j);
    res2+=a[i][j]+call(i+1,j+1);
    return dp[i][j]=max(res1,res2);

}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        int temp=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<2*n-1;i++)
        {
          if(i<n)
          {
              for(int j=0;j<=i;j++)
              {
                scanf("%lld",&a[i][j]);
              }
              for(int j=i+1;j<n;j++)
              {
                a[i][j]=0;
              }
          }
          else
          {
              temp++;
              for(int j=0;j<temp;j++) a[i][j]=0;
              for(int j=temp;j<n;j++) scanf("%lld",&a[i][j]);
          }
        }
        printf("Case %d: %lld\n",++tc,call(0,0));
    }
}


