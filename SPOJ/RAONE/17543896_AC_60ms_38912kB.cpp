#include<bits/stdc++.h>
using namespace std;
#define NN 15
#define ll long long
vector<int> u,l;
long long dp[NN][2][2][2][50][50][10];
int n;

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



long long call(int in , bool flag ,bool islow , bool ishigh, int even,int odd,int pos){
        if(in >= n){
            //cout<<pos<<endl;
           if(pos%2!=0)return (odd-even)==1?1:0;
           else return (even-odd)==1?1:0;
        }
        ll  res = 0;
        if(dp[in][flag][islow][ishigh][even][odd][pos] !=-1)
           return dp[in][flag][islow][ishigh][even][odd][pos];
        for(int i = 0 ; i< 10 ; i++){
             if(islow && i < l[in]) continue;
             if(ishigh && i> u[in]) continue;
             flag=flag | i?1:0;
             if(flag==1 && pos%2==0) res +=call(in+1,flag | i?1:0,islow&(i==l[in]),ishigh&(i==u[in]),even+i,odd,pos+1);
             else if(flag==1 && pos%2!=0) res +=call(in+1,flag | i?1:0,islow&(i==l[in]),ishigh&(i==u[in]),even,odd+i,pos+1);
             else res +=call(in+1,flag,islow&(i==l[in]),ishigh&(i==u[in]),even,odd,pos);
        }
        return dp[in][flag][islow][ishigh][even][odd][pos] =res;
    }

long long solve(long long a,long long b){
    memset(dp,-1,sizeof dp);
    u.clear();
    l.clear();

    findDig(b,u,0);
    findDig(a,l,1);
    n=u.size();

    return call(0,0,1,1,0,0,0);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long left,right;
        cin>>left>>right;
        cout<<solve(left,right)<<endl;
    }
}
