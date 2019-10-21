#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("out.txt","w",stdout);
    map<long long,long long>mp;
    map<long long,pair<int,int> > mrk;
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=i;j++){
            if(mp[(i*i*i)-(j*j*j)]==0){
                mrk[(i*i*i)-(j*j*j)]=make_pair(i,j);
            }
            else if(mp[(i*i*i)-(j*j*j)]==1 && mrk[(i*i*i)-(j*j*j)].second>j){
                mrk[(i*i*i)-(j*j*j)]=make_pair(i,j);
            }
             mp[(i*i*i)-(j*j*j)]=1;
        }
    }
    long long n;
    while(cin>>n){
        if(n==0)break;
        if(mp[n]) cout<<mrk[n].first<<" "<<mrk[n].second<<endl;
        else cout<<"No solution"<<endl;
    }
}
