#include<bits/stdc++.h>
using namespace std;
long long a[1010],dp[1010][1010];

long long call(int i,int j)
{
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    long long res1=0,res2=0;
    if(a[i+1]>=a[j])res1=a[i]+call(i+2,j);
    else res1=a[i]+call(i+1,j-1);
    if(a[j-1]>a[i])res2=a[j]+call(i,j-2);
    else res2=a[j]+call(i+1,j-1);
    return dp[i][j]=max(res1,res2);
}
int main()
{
    int n,tc=0;
    while(cin>>n){
        if(n==0) break;
        long long first,sum=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        first=call(0,n-1);
        cout<<"In game "<<++tc<<", the greedy strategy might lose by as many as "<<(2*first)-sum<<" points."<<endl;
    }
}
