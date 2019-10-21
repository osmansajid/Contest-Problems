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

bool check(long long hashVal[],int mid,string s){
    long long x=hashValBetween(1,mid,hashVal);
    for(int i=2;i+mid-1<s.size();i++){
        if(hashValBetween(i,i+mid-1,hashVal)==x){
            return true;
        }
    }
    return false;
}

int main()
{
    powercal();
    string s;
    cin>>s;
    long long hashVal[s.size()+10];
    hashFuntion(s,hashVal);
    vector<int> v;
    for(int len=1;len<=s.size();len++){
        if(hashValBetween(1,len,hashVal)==hashValBetween(s.size()-len+1,s.size(),hashVal)){
            v.push_back(len);
        }
    }
    int low=0,high=v.size()-1,mid,ans=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(check(hashVal,v[mid],s)){
            low=mid+1;
            ans=v[mid];
        }
        else{
            high=mid-1;
        }
    }
    if(ans==-1){
        cout<<"Just a legend"<<endl;
    }
    else{
        for(int i=0;i<ans;i++) cout<<s[i];
        cout<<endl;
    }
}
