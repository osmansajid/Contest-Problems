#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,lim,cur;
    cin>>n>>k;
    lim=sqrt(n);
    set<long long>div;
    bool flag=false;
    if(n<k || k>10000000){
        cout<<-1<<endl;
        return 0;
    }
    for(long long i=lim;i>=1;i--){
        if(n%i==0){
            div.insert(i);
            div.insert(n/i);
        }
    }
    set<long long>:: iterator it;
    long long divisor;
    for(it=div.begin();it!=div.end();it++){
        if((*it)*(k+1)*(k)/2<=n){
            flag=true;
            divisor=*it;
        }
        else break;
    }
    if(flag){
        set<long long> ans;
        long long cur=0;
        for(long long i=1;i<=k-1;i++){
            ans.insert(i*(divisor));
            cur+=(i*(divisor));
        }
        ans.insert(n-cur);
        if(ans.size()!=k){
            cout<<-1<<endl;
            return 0;
        }
        for(it=ans.begin();it!=ans.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
        return 0;
    }
    else{
        cout<<-1<<endl;
        return 0;
    }
}
