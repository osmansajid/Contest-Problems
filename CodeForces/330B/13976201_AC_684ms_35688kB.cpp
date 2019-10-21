#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    map<pair<int,int>, int> mp;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        mp[make_pair(u,v)]=1;
        mp[make_pair(v,u)]=1;
    }
    cout<<n-1<<endl;
    int ans;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(i!=j){
                if(mp[make_pair(j,i)]==0 && mp[make_pair(i,j)]==0){
                    cnt++;
                }
            }
        }
        if(cnt==n-1){
            ans=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=ans){
            if(mp[make_pair(ans,i)]==0 && mp[make_pair(i,ans)]==0){
                cout<<ans<<" "<<i<<endl;
            }
        }
    }
}
