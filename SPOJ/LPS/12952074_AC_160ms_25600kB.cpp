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

bool check(int len,long long hashVal[],long long hashVal2[],string s){
    for(int i=0;i+len-1<s.size();i++){
        if(hashValBetween(i+1,i+len,hashVal)==hashValBetween(s.size()-(i+len)+1,s.size()-(i),hashVal2)){
            return true;
        }
    }
    return false;
}

int main()
{
    powercal();
    int n,ans1=0,ans2=0;
    cin>>n;
    string s,r;
    cin>>s;
    r=s;
    reverse(r.begin(),r.end());
    long long hashVal[s.size()],hashVal2[s.size()];
    hashFuntion(s,hashVal);
    hashFuntion(r,hashVal2);

    vector<int> e;
    vector<int> o;
    for(int i=1;i<=s.size();i+=2)o.push_back(i);
    for(int i=2;i<=s.size();i+=2)e.push_back(i);

    int low=0,high=o.size()-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        //cout<<o[mid]<<endl;
        if(check(o[mid],hashVal,hashVal2,s)){
            low=mid+1;
            ans1=o[mid];
        }
        else{
            high=mid-1;
        }
    }

    low=0,high=e.size()-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(check(e[mid],hashVal,hashVal2,s)){
            low=mid+1;
            ans2=e[mid];
        }
        else{
            high=mid-1;
        }
    }

    cout<<max(ans1,ans2)<<endl;
}
