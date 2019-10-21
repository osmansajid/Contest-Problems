#include<bits/stdc++.h>
using namespace std;
#define mod 2117566807
#define base 1971536491
#define N 1000001
map<long long,long long>mp;

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

int check(int mid,long long hashVal[],int n){
    long long ret=0;
    for(int i=0;i+mid<=n;i++){
        long long x=hashValBetween(i+1,i+mid,hashVal);
        mp[x]++;
        //if(x==986076691) cout<<i+1<<" "<<i+mid<<endl;
        ret=max(ret,mp[x]);
    }
    return ret;
}

string findmax(string a,string b){
    for(int i=0;i<a.size();i++){
        if(a[i]<b[i]) return a;
        else if(a[i]>b[i]) return b;
    }
    return a;
}

string fun(int len,string s,int ocur,long long hashVal[]){
    int flg=false;
    string ans;
    for(int i=0;i+len<=s.size();i++){
        long long x=hashValBetween(i+1,i+len,hashVal);
        if(mp[x]==ocur){
            string x;
            for(int j=i;j<i+len;j++)x.push_back(s[j]);
            if(!flg){
                ans=x;
                flg=true;
            }
            else{
                ans=findmax(ans,x);
            }
        }
    }
    return ans;
}

int main()
{
    powercal();
    //ofstream my("input.txt");
    int t,tc=0;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long hashVal[s.size()+10];
        hashFuntion(s,hashVal);
        int lo=1,hi=s.size(),mid,ans=-1,ocur;
        while(lo<=hi){
            mid=(lo+hi)/2;
            int cnt=check(mid,hashVal,s.size());
            if(cnt>1){
                lo=mid+1;
                ans=mid;
                ocur=cnt;
            }
            else{
                hi=mid-1;
            }
        }
        if(ans==-1) cout<<"No repetitions found!"<<endl;
        else cout<<fun(ans,s,ocur,hashVal)<<" "<<ocur<<endl;
        mp.clear();
    }
}
