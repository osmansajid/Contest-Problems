#include<bits/stdc++.h>
using namespace std;
int dp[100000];
int n,r[100000];
int fun(int indx)
{
    if(indx>=n*3){
        return 0;
    }
    if(dp[indx]!=-1){
        return dp[indx];
    }
    int res1=1000000,res2=1000000;
    if(indx%3==0){
        res1=r[indx]+fun(indx+4);
        res2=r[indx]+fun(indx+5);
        return dp[indx]=min(res1,res2);
    }
    if(indx%3==1){
        res1=r[indx]+fun(indx+2);
        res2=r[indx]+fun(indx+4);
        return dp[indx]=min(res1,res2);
    }
    if(indx%3==2){
        res1=r[indx]+fun(indx+1);
        res2=r[indx]+fun(indx+2);
        return dp[indx]=min(res1,res2);
    }
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin>>n;
        int j=0;
        for(int i=0;i<n;i++){
            cin>>r[j]>>r[j+1]>>r[j+2];
            j+=3;
        }
        cout<<"Case "<<++tc<<": "<<min(fun(0),min(fun(1),fun(2)))<<endl;;
    }
}
