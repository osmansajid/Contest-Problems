#include<bits/stdc++.h>
using namespace std;
int dp[(1<<15)+2],n,a[20][20];

int Set(int mask,int pos){
    return mask=mask|(1<<pos);
}
int reset(int mask,int pos){
    return mask=mask&~(1<<pos);
}
bool check(int mask,int pos){
    return (bool)(mask&(1<<pos));
}
int call(int mask){
    if(mask==(1<<n)-1){
        return 0;
    }
    if(dp[mask]!=-1){
        return dp[mask];
    }
    int p,mini=1<<28;
    for(int i=0;i<n;i++){
        if(check(mask,i)==false){
            p=a[i][i];
            for(int j=0;j<n;j++){
                if(i!=j && check(mask,j)==true){
                    p+=a[i][j];
                }
            }
            int res=p+call(Set(mask,i));
            mini=min(res,mini);
        }
    }
    return dp[mask]=mini;
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
        cout<<"Case "<<++tc<<": "<<call(0)<<endl;
    }
}
