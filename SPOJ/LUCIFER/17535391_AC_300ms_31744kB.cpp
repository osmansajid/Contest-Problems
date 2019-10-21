#include<bits/stdc++.h>
using namespace std;

#define NN 10
#define ll long long
vector<int> u,l;
long long dp[NN][2][2][2][50][50][NN];
int n,isprime[101];

void prime(){
    isprime[1]=isprime[0]=0;
    for(int i=2;i<=100;i++){
        bool flg=true;
        for(int j=2;j<i;j++){
            if(i%j==0){
                flg=false;
                break;
            }
        }
        if(flg) isprime[i]=1;
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



long long call(int in , bool flag ,bool islow , bool ishigh,int odd,int even,int pos){
        if(in >= n){
            if(pos%2!=0){
                if(odd>even) return isprime[odd-even];
                return 0;
            }
            else{
                if(even>odd) return isprime[even-odd];
                return 0;
            }
        }
        ll  res = 0;
        if(dp[in][flag][islow][ishigh][odd][even][pos] !=-1)
           return dp[in][flag][islow][ishigh][odd][even][pos];
        for(int i = 0 ; i< 10 ; i++){
             if(islow && i < l[in]) continue;
             if(ishigh && i> u[in]) continue;
             flag=flag | i?1:0;
             if(flag==1 && pos%2==0)res +=call(in+1,flag,islow&(i==l[in]),ishigh&(i==u[in]),odd,even+i,pos+1);
             else if(flag==1 && pos%2!=0)res +=call(in+1,flag,islow&(i==l[in]),ishigh&(i==u[in]),odd+i,even,pos+1);
             else res +=call(in+1,flag,islow&(i==l[in]),ishigh&(i==u[in]),odd,even,pos);
        }
        return dp[in][flag][islow][ishigh][odd][even][pos] =res;
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
    prime();
    int t;
    cin>>t;
    while(t--){
       // for(int i=1;i<=100;i++) cout<<isprime[i]<<endl;
        long long left,right;
        cin>>left>>right;
        cout<<solve(left,right)<<endl;
    }
}
