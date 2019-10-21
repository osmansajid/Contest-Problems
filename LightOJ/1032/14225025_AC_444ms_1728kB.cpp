#include<bits/stdc++.h>
using namespace std;
long long dp[35][35][2][2];

void findDig(long long a,vector<int> &dig){
    while(a!=0){
        dig.push_back(a%2);
        a/=2;
    }
}
vector<int>v;

long long call(int indx,long long sum,int tight,int prev,vector<int> &dig){
    if(indx==-1){
        //cout<<endl;
//        for(int i=0;i<v.size();i++) cout<<v[i];
//        cout<<" "<<sum<<endl;
        return sum;
    }
    if(dp[indx][sum][prev][tight]!=-1 && tight!=1){
        return dp[indx][sum][prev][tight];
    }
    long long res=0;
    int lo=0;
    int hi=(tight)?dig[indx]:1;
    for(int i=lo;i<=hi;i++){
       // v.push_back(i);
        res+=call(indx-1,(prev==1&&i==1)?sum+1:sum,tight&(i==hi),i,dig);
        //v.pop_back();
    }
    if(!tight){
        dp[indx][sum][prev][tight]=res;
    }
    return res;
}

long long solve(long long a){
    memset(dp,-1,sizeof dp);

    vector<int> digA;
    findDig(a,digA);
    //for(int i=digA.size()-1;i>=0;i--)cout<<digA[i];
    long long resA=call(digA.size()-1,0,1,-1,digA);
    return resA;
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        long long a;
        cin>>a;
        cout<<"Case "<<++tc<<": "<<solve(a)<<endl;
    }
}
