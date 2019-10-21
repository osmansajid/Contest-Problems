#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define base 1572872831
#define N 100000
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
    int n;
    while(cin>>n){
        string sub,s;
        cin>>sub>>s;
        if(sub.size()>s.size()) cout<<endl;
        else{
            long long hashVal1[sub.size()],hashVal2[s.size()];
            hashFuntion(sub,hashVal1);
            hashFuntion(s,hashVal2);
            long long x=hashValBetween(1,sub.size(),hashVal1);
            for(int i=0;i<=s.size()-sub.size();i++){
               if(hashValBetween(i+1,i+sub.size(),hashVal2)==x){
                    cout<<i<<endl;
               }
            }
        }
        cout<<endl;
    }
}
