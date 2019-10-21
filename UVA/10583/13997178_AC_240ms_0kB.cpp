#include<bits/stdc++.h>
using namespace std;
#define N 50010
int pr[N];

int find(int r){
    return pr[r]= pr[r]==r?r:find(pr[r]);
}

int main()
{
    int n,m,tc=0;
    while(cin>>n>>m){
        if(n==0 && m==0) break;
        int cnt=0;
        map<int,int>mp;
        for(int i=1;i<=n;i++) pr[i]=i;
        for(int i=0;i<m;i++){
            int u,v,x,y;
            cin>>u>>v;
            x=find(u);
            y=find(v);
            if(x!=y){
                pr[x]=y;
            }
        }
        for(int i=1;i<=n;i++){
            if(!mp[find(i)]){
                cnt++;
                mp[find(i)]++;
            }
        }
        cout<<"Case "<<++tc<<": "<<cnt<<endl;
    }
}
