#include<bits/stdc++.h>
using namespace std;
struct team{
    int pr,pn;
} t[100];

bool operator< (team obj,team obj2){
        if(obj.pr==obj2.pr){
            return obj.pn<obj2.pn;
        }
        return obj.pr>obj2.pr;
}

int main(){
    int n,q,cnt=0;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>t[i].pr>>t[i].pn;
    }
    sort(t,t+n);
    int xpr,xpn;
    xpr=t[q-1].pr;
    xpn=t[q-1].pn;
    for(int i=0;i<n;i++){
        //cout<<i+1<<" I "<<endl;
        if(t[i].pr==xpr && t[i].pn==xpn){
            cnt++;
           // cout<<cnt<<" C "<<endl;
        }
    }
    cout<<cnt<<endl;
}
