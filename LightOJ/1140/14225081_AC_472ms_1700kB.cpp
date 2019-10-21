#include<bits/stdc++.h>
using namespace std;
long long dp[16][20][2][2];

void findDig(long long a,vector<int> &dig){
    while(a!=0){
        dig.push_back(a%10);
        a/=10;
    }
}
vector<int>v;

long long call(int indx,long long sum,int flg,int tight,vector<int> &dig){
    if(indx==-1){
        return sum;
    }
    if(dp[indx][sum][flg][tight]!=-1 && tight!=1){
        return dp[indx][sum][flg][tight];
    }
    long long res=0;
    int lo=0;
    int hi=(tight)?dig[indx]:9;
    for(int i=lo;i<=hi;i++){
        res+=call(indx-1,(flg==1 && i==0)? sum+1:sum,(i)?1:flg,tight&(i==hi),dig);
    }
    if(!tight){
        dp[indx][sum][flg][tight]=res;
    }
    return res;
}

long long solve(long long a,long long b){
    memset(dp,-1,sizeof dp);

    vector<int> digA;
    findDig(a-1,digA);
    long long resA=call(digA.size()-1,0,0,1,digA);

    vector<int> digB;
    findDig(b,digB);
    long long resB=call(digB.size()-1,0,0,1,digB);

    return resB-resA+(a?0:1);
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        cout<<"Case "<<++tc<<": "<<solve(a,b)<<endl;
    }
}

