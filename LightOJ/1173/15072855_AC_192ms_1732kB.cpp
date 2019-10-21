#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long dp[52][2][52];

unsigned long long call(int cur,int fl,int rem,int noob[])
{
    if(rem==0) return 1ULL;
    if(dp[cur][fl][rem]!=-1) return dp[cur][fl][rem];
    unsigned long long res=0;
    if(fl){
        for(int i=1;i<cur;i++){
            //cout<<noob[i]<<" "<<i<<" "<<cur<<endl;
            if(!noob[i]){
                noob[i]=1;
                res=res+call(i,0,rem-1,noob);
                noob[i]=0;
            }
        }
    }
    else{
        for(int i=cur+1;i<=n;i++){
            //cout<<noob[i]<<" "<<i<<" "<<cur<<endl;
            if(!noob[i]){
                noob[i]=1;
                res=res+call(i,1,rem-1,noob);
                noob[i]=0;
            }
        }
    }
    return dp[cur][fl][rem]=res;
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int noob[n+10];
        memset(noob,0,sizeof noob);
        memset(dp,-1,sizeof dp);
        if(m==1 && n==1) cout<<"Case "<<++tc<<": "<<1<<endl;
        else if(m==1){
            noob[m]=1;
            noob[m+2]=1;
            cout<<"Case "<<++tc<<": "<<call(m+2,1,n-2,noob)<<endl;
        }
        else{
            noob[m]=1;
            cout<<"Case "<<++tc<<": "<<call(m,1,n-1,noob)<<endl;
        }
    }
}
