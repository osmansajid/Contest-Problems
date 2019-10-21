#include<bits/stdc++.h>
using namespace std;
int dp[(1<<15)+2],n,h[20],d[20][20];

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
    int mini=1<<28;
    for(int i=0;i<n;i++){
        if(check(mask,i)==false){
            int w=1;
            for(int j=0;j<n;j++){
                if(check(mask,j)==true){
                    w=max(w,d[j][i]);
                }
            }
            float x=(float)h[i]/(float)w;
            int res=ceil(x)+call(Set(mask,i));
            mini=min(mini,res);
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
        string s[n];
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            cin>>h[i];
        }
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=s[i][j]-'0';
            }
        }
        cout<<"Case "<<++tc<<": "<<call(0)<<endl;
    }
}
