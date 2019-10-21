#include<bits/stdc++.h>
using namespace std;
long long dp[19][19][2];

void findDig(long long a,vector<int> &dig){
    while(a!=0){
        dig.push_back(a%10);
        a/=10;
    }
}

bool check(int idx,int len,vector<int> &dig,long long a){
    long long x=0;
    for(int i=dig.size()-1;i>idx;i--){
        x=(x*10)+dig[i];
    }
    for(int i=idx+((len%2)? 2:1);i<len;i++){
        x=(x*10)+dig[i];
    }
    if(x<=a) return 1;
    return 0;
}

long long call(int idx,int len,int tight,vector<int> &dig,long long a){
    if(idx==((len)/2)-1){
        if(tight) return check(idx,len,dig,a);
        else return 1;
    }
    if(dp[idx][len][tight]!=-1 && tight!=1){
        return dp[idx][len][tight];
    }
    long long res=0;
    int k=(tight)?dig[idx]:9;
    for(int i=0;i<=k;i++){
        int newtight=(dig[idx]==i)?tight:0;
        res+=call(idx-1,(i)?((len==0)?idx+1:len):len,newtight,dig,a);
    }
    if(tight==0){
        dp[idx][len][tight]=res;
    }
    return res;
}

long long result(long long a,long long b){
    memset(dp,-1,sizeof dp);

    vector<int> digA;
    findDig(a-1,digA);
    long long resA=call(digA.size()-1,0,1,digA,a-1);

    vector<int> digB;
    findDig(b,digB);
    long long resB=call(digB.size()-1,0,1,digB,b);

    return resB-resA;
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        long long x=result(a,b);
        cout<<"Case "<<++tc<<": "<<x<<endl;
    }
}
