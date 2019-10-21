#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    m=n+1;
    n=n-1;
    vector<int> ans1,ans2;
    while(n){
        ans1.push_back(n%10);
        n/=10;
    }
    while(m){
        ans2.push_back(m%10);
        m/=10;
    }
    while(ans1.size()!=6) ans1.push_back(0);
    while(ans2.size()!=6) ans2.push_back(0);
    int a,b,c,d;
    a=ans1[0]+ans1[1]+ans1[2];
    b=ans1[3]+ans1[4]+ans1[5];
    c=ans2[0]+ans2[1]+ans2[2];
    d=ans2[3]+ans2[4]+ans2[5];
    if(a==b || c==d) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
