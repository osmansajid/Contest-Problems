#include<bits/stdc++.h>
using namespace std;
long long And,Or;
int tc=0;

long long Set(long long mask,int pos){
    return mask=mask|(1LL<<pos);
}
long long reset(long long mask,int pos){
    return mask=mask&~(1LL<<pos);
}
bool check(long long mask,int pos){
    if(pos<0) return false;
    return (bool)(mask&(1LL<<pos));
}

void findDig(long long a,vector<int> &dig){
    while(a!=0){
        dig.push_back(a%2);
        a/=2;
    }
}

void fillup(vector<int> &dig,int upto){
    while(dig.size()!=upto){
        dig.push_back(0);
    }
}

long long call(int indx,int lotight,int hitight,vector<int> &dig1,vector<int> &dig2){
    if(indx==-1){
        return 0;
    }
//    if(dp[indx][lotight][hitight]!=-1 && lotight!=1 && hitight!=1){
//        return dp[indx][lotight][hitight];
//    }
    //long long res=0;
    int lo=(lotight)?dig1[indx]:0;
    int hi=(hitight)?dig2[indx]:1;
    for(int i=lo;i<=hi;i++){
        if(i==0) And=reset(And,indx);
        if(i==1) Or=Set(Or,indx);
        if(check(Or,indx-1)!=true || check(And,indx-1)!=false)call(indx-1,lotight&(i==lo),hitight&(i==hi),dig1,dig2);
    }
//    if(lotight==0 && hitight==0){
//        dp[indx][lotight][hitight]=res;
//    }
}

void solve(long long a,long long b){
//    memset(dp,-1,sizeof dp);

    vector<int> digA;
    findDig(a,digA);

    vector<int> digB;
    findDig(b,digB);

    if(digB.size()>digA.size()) fillup(digA,digB.size());
//    for(int i=0;i<digA.size();i++) cout<<digA[i];
//    cout<<endl;
//    for(int i=0;i<digB.size();i++) cout<<digB[i];
//    cout<<endl;
    And=(1LL<<digA.size())-1;
    Or=0;
    call(digB.size()-1,1,1,digA,digB);

    cout<<"Case "<<++tc<<": "<<Or<<" "<<And<<endl;
}

int main()
{
    
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        solve(a,b);
    }
}
