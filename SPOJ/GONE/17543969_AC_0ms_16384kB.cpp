#include<bits/stdc++.h>
using namespace std;
#define NN 15
#define ll long long
vector<int> u,l;
long long dp[NN][2][2][200];
int n,isprime[201];

void prime()
{
    isprime[0]=0;
    isprime[1]=0;
    for(int i=2;i<=200;i++){
        int flg=0;
        for(int j=2;j<i;j++){
            if(i%j==0){
                flg=1;
                break;
            }
        }
        if(flg==0) isprime[i]=1;
    }
}

void findDig(long long a,vector<int> &dig,int flag){
    while(a!=0){
        dig.push_back(a%10);
        a/=10;
    }
    if(flag){
        while(dig.size()!=u.size()) dig.push_back(0);
    }
    reverse(dig.begin(),dig.end());
}



long long call(int in ,bool islow , bool ishigh,int carry){
        if(in >= n)
           return isprime[carry];
        ll  res = 0;
        if(dp[in][islow][ishigh][carry] !=-1)
           return dp[in][islow][ishigh][carry];
        for(int i = 0 ; i< 10 ; i++){
             if(islow && i < l[in]) continue;
             if(ishigh && i> u[in]) continue;
             res +=call(in+1,islow&(i==l[in]),ishigh&(i==u[in]),carry+i);
        }
        return dp[in][islow][ishigh][carry] =res;
    }

long long solve(long long a,long long b){
    memset(dp,-1,sizeof dp);
    u.clear();
    l.clear();

    findDig(b,u,0);
    findDig(a,l,1);
    n=u.size();

    return call(0,1,1,0);
}


int main()
{
    prime();
    int t;
    cin>>t;
    while(t--){
        long long left,right;
        cin>>left>>right;
        cout<<solve(left,right)<<endl;
    }
}
