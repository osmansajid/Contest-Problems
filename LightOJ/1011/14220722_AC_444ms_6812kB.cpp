#include<bits/stdc++.h>
using namespace std;
int a[20][20],dp[20][(1<<16)+2],n;

int Set(int mask,int pos){
    return mask=mask|(1<<pos);
}
int reset(int mask,int pos){
    return mask=mask&~(1<<pos);
}
bool check(int mask,int pos){
    return (bool)(mask&(1<<pos));
}

int call(int indx,int mask)
{
    if(mask==(1<<n)){
        return 0;
    }
    if(dp[indx][mask]!=-1) return dp[indx][mask];
    int res=0;
    for(int i=0;i<n;i++){
        if(!check(mask,i)){
            res=max(res,a[indx][i]+call(indx+1,Set(mask,i)));
        }
    }
    return dp[indx][mask]=res;
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        cout<<"Case "<<++tc<<": "<<call(0,0)<<endl;
    }
}
