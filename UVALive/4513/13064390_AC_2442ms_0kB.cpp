#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define base 1572872831
#define N 1000001
int lef=-1,m;


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
    int ret=0;
    unordered_map<long long,long long>mp;
    for(int i=0;i+mid<=n;i++){
        long long x=hashValBetween(i+1,i+mid,hashVal);
        mp[x]++;
        if(mp[x]>=m){
            ret=mp[x];
        }
    }
    return ret;
}

int findpos(int len,long long hashVal[],int n){
    int ret;
    unordered_map<long long,long long>mp;
    for(int i=0;i+len<=n;i++){
        long long x=hashValBetween(i+1,i+len,hashVal);
        mp[x]++;
    }
    for(int i=0;i+len<=n;i++){
        long long x=hashValBetween(i+1,i+len,hashVal);
        if(mp[x]>=m) ret=i;
    }
    return ret;
}

int main()
{
    powercal();
//    int m;
//    ofstream myfile;
//    myfile.open ("input.txt");
    while(cin>>m){
        if(m==0) break;
        string s;
        cin>>s;
        long long hashVal[s.size()+10];
        hashFuntion(s,hashVal);
        int lo=1,hi=s.size(),mid,ans=0,ans2=0,n=s.size();
        //for(int i=1;i<=s.size();i++)cout<<hashValBetween(i,i,hashVal)<<endl;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(check(mid,hashVal,n)>=m){
                lo=mid+1;
                ans=mid;
                ans2=lef;
                lef=-1;
            }
            else{
                hi=mid-1;
            }
        }

        if(ans) cout<<ans<<" "<<findpos(ans,hashVal,n)<<endl;
        else cout<< "none\n";
    }
//    myfile.close();
}
