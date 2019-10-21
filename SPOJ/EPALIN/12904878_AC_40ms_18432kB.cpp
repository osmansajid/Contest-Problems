#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define base 1572872831
#define N 100001
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
    string s;
    while(cin>>s){
        int ans;
        string r=s;
        reverse(s.begin(),s.end());
        long long hashVal1[s.size()+10],hashVal2[r.size()+10];
        hashFuntion(s,hashVal1);
        hashFuntion(r,hashVal2);
        for(int len=s.size();len>0;len--){
            if(hashValBetween(1,len,hashVal1)==hashValBetween(r.size()-len+1,r.size(),hashVal2)){
                ans=len;
                break;
            }
            else{
                continue;
            }
        }
        cout<<r;
        for(int i=ans;i<s.size();i++){
            cout<<s[i];
        }
        cout<<endl;
    }
}
