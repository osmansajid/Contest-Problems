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

bool check(int len,long long hashVal1[],long long hashVal2[],string s){
    for(int i=0;i+len-1<s.size();i++){
        if(hashValBetween(i+1,i+len,hashVal1)==hashValBetween(1,len,hashVal2)){
            return true;
        }
    }
    return false;
}

int main()
{
    powercal();
    int t;
    cin>>t;
    while(t--){
        int ans=0;
        string s,r;
        cin>>s;
        r=s;
        reverse(s.begin(),s.end());
        long long hashVal1[s.size()],hashVal2[r.size()];
        hashFuntion(s,hashVal1);
        hashFuntion(r,hashVal2);

        int low=1,high=s.size(),mid;
        while(low<=high){
            mid=(low+high)/2;
            if(check(mid,hashVal1,hashVal2,s)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        for(int i=ans-1;i>=0;i--){
            cout<<r[i];
        }
        cout<<endl;
    }
}
