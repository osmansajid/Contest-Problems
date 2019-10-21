#include<bits/stdc++.h>
using namespace std;
long long freq[100008],dp[100008],m;

long long call(int i)
{
    if(i>m){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    long long res1=0,res2=0;
    res1=freq[i]*i+call(i+2);
    res2=freq[i]*i+call(i+3);
    return dp[i]=max(res1,res2);
}
int main()
{
    long long n;
    cin>>n;
    long long a[n+10];
    memset(dp,-1,sizeof dp);
    memset(freq,0,sizeof freq);
    for(int i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]++;
        m=max(a[i],m);
    }
    cout<<max(call(1),call(2))<<endl;
}
