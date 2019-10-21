#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define base 1572872831
#define N 1000001

long long Power[N];
void powercal(){
    Power[0]=1;
    for(int i=1;i<N;i++){
        Power[i]=((Power[i-1]%mod)*(base%mod))%mod;
    }
}

void hashFuntion(string s,long long hashVal[]){
    hashVal[0]=0;
    for(int i=0;i<s.size();i++){
            hashVal[i+1]=(hashVal[i]*base + s[i])%mod;
    }
}

long long hashValBetween(int i,int j,long long hashVal[]){
    return ((hashVal[j]-hashVal[i-1]*Power[j-i+1])%mod+mod)%mod;
}

int main()
{
    powercal();
    string x;
    while(getline(cin,x)){
        //cout<<x<<endl;
        string s;
        map<long long,long long>mp;
        for(int i=0;i<x.size();i++){
            if(x[i]!=' '){
                s.push_back(x[i]);
            }
        }
        //cout<<s<<endl;
        long long hashVal[s.size()];
        if(s.size()==0) break;
        hashFuntion(s,hashVal);
        for(int len=1;len<=s.size();len++){
            long long ans=0;
            for(int i=0;i+len<=s.size();i++){
                mp[hashValBetween(i+1,i+len,hashVal)]++;
                //cout<<hashValBetween(i+1,i+len,hashVal)<<endl;
                ans=max(ans,mp[hashValBetween(i+1,i+len,hashVal)]);
            }
            if(ans>1) cout<<ans<<endl;
            else break;
        }
    }
}
