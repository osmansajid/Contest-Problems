#include<bits/stdc++.h>
using namespace std;
#define NN 19
#define ll long long
vector<int> u,l;
long long dp[NN][2][2][166][166];
int n,k;

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



long long call(int in ,bool islow , bool ishigh,int carry,int sum){
        if(in >= n)
           return (carry==0 && sum%k==0)?1:0;
        ll  res = 0;
        if(dp[in][islow][ishigh][carry][sum] !=-1)
           return dp[in][islow][ishigh][carry][sum];
        for(int i = 0 ; i< 10 ; i++){
             if(islow && i < l[in]) continue;
             if(ishigh && i> u[in]) continue;
             res +=call(in+1,islow&(i==l[in]),ishigh&(i==u[in]),(carry*10+i)%k,sum+i);
        }
        return dp[in][islow][ishigh][carry][sum]=res;
    }

long long solve(long long a,long long b){
    memset(dp,-1,sizeof dp);
    u.clear();
    l.clear();

    findDig(b,u,0);
    findDig(a,l,1);
    n=u.size();

    return call(0,1,1,0,0);
}


int main()
{
    //freopen("out.txt","w",stdout);
    int t,tc=0;
    cin>>t;
    while(t--){
        long long left,right;
        cin>>left>>right>>k;

        if(k<=165)cout<<"Case "<<++tc<<": "<<solve(left,right)<<endl;
        else cout<<"Case "<<++tc<<": "<<0<<endl;
    }
}
