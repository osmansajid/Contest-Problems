#include<bits/stdc++.h>
using namespace std;
long long dp[19][165][2][165],k;

void findDig(long long a,vector<int> &dig){
    while(a!=0){
        dig.push_back(a%10);
        a/=10;
    }
}

long long call(int idx,int sum,int tight,int val,vector<int> &dig){
    if(idx==-1){
        return (sum%k==0)&&(val%k==0);
    }
    if(dp[idx][sum][tight][val]!=-1 && tight!=1){
        return dp[idx][sum][tight][val];
    }
    long long res=0;
    int x=(tight)?dig[idx]:9;
    for(int i=0;i<=x;i++){
        int newtight=(dig[idx]==i)?tight:0;
        res+=call(idx-1,sum+i,newtight,(((val*10)+i)%k),dig);
    }
    if(tight==0){
        dp[idx][sum][tight][val]=res;
    }
    return res;
}

long long result(long long a,long long b){
    memset(dp,-1,sizeof dp);

    vector<int> digA;
    findDig(a-1,digA);
    long long resA=call(digA.size()-1,0,1,0,digA);

    vector<int> digB;
    findDig(b,digB);
    long long resB=call(digB.size()-1,0,1,0,digB);

    return resB-resA;
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b>>k;
        if(k>165)cout<<"Case "<<++tc<<": "<<0<<endl;
        else cout<<"Case "<<++tc<<": "<<result(a,b)<<endl;
    }
}
