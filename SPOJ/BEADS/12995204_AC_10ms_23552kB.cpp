#include<bits/stdc++.h>
using namespace std;
#define mx 999999999999999999
#define mod 1000000007
#define base 1572872831
#define N 1000001
long long Power[N];
string s;

void powercal(){
    Power[0]=1;
    for(int i=1;i<N;i++){
        Power[i]=((Power[i-1]%mod)*(base%mod))%mod;
    }
}

void hashFuntion(string s,long long hashVal[]){
    hashVal[0]=0;
    for(int i=0;i<s.size();i++){
            hashVal[i+1]=(hashVal[i]*base + s[i]+mod)%mod;
    }
}

long long hashValBetween(int i,int j,long long hashVal[]){
    return ((hashVal[j]-hashVal[i-1]*Power[j-i+1])%mod+mod)%mod;
}

int check(int maxi,int i,int len,long long hashVal[]){
    int lo=0,hi=len,mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(hashValBetween(maxi+1,maxi+mid,hashVal)==hashValBetween(i+1,i+mid,hashVal)){
            lo=mid+1;
        }
        else hi=mid-1;
    }
    if(s[maxi+hi]<=s[i+hi]) return maxi;
    return i;
}
int main()
{
    powercal();
    int n;
    cin>>n;
    while(n--){
        cin>>s;
        int maxi=0,x=0;
        int len=s.size();
        s+=s;
        long long hashVal[s.size()+10];
        hashFuntion(s,hashVal);
        for(int i=0;i<len;i++){
            maxi=check(maxi,i,len,hashVal);
        }
        cout<<maxi+1<<endl;
    }
}
