#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define base 1572872831
#define N 100001
string s,r;
long long hashvalorg[N],hashvalrev[N];
int pos;

//const long long mod[] = {1000000007LL, 2117566807LL};
//const long long base[] = {1572872831LL, 1971536491LL};

long long Power[N];
void powercal(){
    Power[0]=1;
    for(int i=1;i<N;i++){
        Power[i]=((Power[i-1]%mod)*(base%mod))%mod;
    }
}

void hashFunction(string s,long long hashVal[]){
    hashVal[0]=0;
    for(int i=0;i<s.size();i++){
            hashVal[i+1]=(hashVal[i]*base + s[i])%mod;
    }
}

long long hashValBetween(int i,int j,long long hashVal[]){
    return ((hashVal[j]-hashVal[i-1]*Power[j-i+1])%mod+mod)%mod;
}

bool check(int len){
    for(int i=0;i<s.size();i++){
        int j=i+len-1;
        if(j>=s.size())break;
        int k=s.size()-j-1;
        int l=s.size()-i-1;
        if(hashValBetween(i+1,j+1,hashvalorg)==hashValBetween(k+1,l+1,hashvalrev)){
                pos=i;
                return true;
        }
    }
    return false;
}


int main()
{
    int maxi;
    powercal();
    cin>>s;
    //clr();
    r=s;
    reverse(r.begin(),r.end());
    hashFunction(s,hashvalorg);
    hashFunction(r,hashvalrev);
    for(int i=1;i<=s.size();i++){
        if(check(i)) maxi=i;
    }
    for(int i=pos;i<pos+maxi;i++) cout<<s[i];
    cout<<endl;
}
