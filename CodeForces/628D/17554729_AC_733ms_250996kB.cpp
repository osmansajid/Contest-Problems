#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define NN 2001
#define ll long long
vector<int> u,l;
long long dp[NN][2][2][2][NN];
int n,d,m;

void findDig(string a,vector<int> &dig){
    for(int i=0;i<a.size();i++){
        dig.push_back(a[i]-'0');
    }
}

long long call(int in , bool flag ,bool islow , bool ishigh,int pos,int carry){
        if(in >= n){
            //cout<<carry<<endl;
           return carry==0?1:0;
        }
        ll  res = 0;
        if(dp[in][flag][islow][ishigh][carry]!=-1)
           return dp[in][flag][islow][ishigh][carry]%MOD;
        for(int i = 0 ; i< 10 ; i++){

            if(islow && i < l[in]) continue;
            if(ishigh && i> u[in]) continue;
           // cout<<pos<<" "<<i<<endl;
            flag=flag | i?1:0;
            if(pos%2==0 && i==d){
                res =(res%MOD + call(in+1,flag,islow&(i==l[in]),ishigh&(i==u[in]),pos+1,(carry*10+d)%m)%MOD)%MOD;
            }
            else if(pos%2!=0 && i!=d){
                res =(res%MOD + call(in+1,flag,islow&(i==l[in]),ishigh&(i==u[in]),pos+1,(carry*10+i)%m)%MOD)%MOD;
            }
        }
        return dp[in][flag][islow][ishigh][carry]=res%MOD;
    }

long long solve(string a,string b){
    memset(dp,-1,sizeof dp);
    u.clear();
    l.clear();

    findDig(b,u);
    findDig(a,l);
    n=u.size();

    return call(0,0,1,1,1,0);
}

int main()
{
    cin>>m>>d;
    string a,b;
    cin>>a>>b;
    cout<<solve(a,b)<<endl;
}
