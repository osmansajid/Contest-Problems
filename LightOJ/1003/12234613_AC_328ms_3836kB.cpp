#include<bits/stdc++.h>
using namespace std;
int cycle=0;
map<string, vector<string> > adj;
map<string,int> vis,mp;

void dfs(string s)
{
    vis[s]=1;
    for(int i=0;i<adj[s].size();i++){
        string u=adj[s][i];
        if(vis[u]==0){
            dfs(u);
        }
        if(vis[u]==1){
            cycle=1;
        }
    }
    vis[s]=2;
    return;
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int m,j=0;
        scanf("%d",&m);
        string st[20010];
        for(int i=0;i<m;i++){
            string a,b;
            cin>>a>>b;
            if(mp[a]==0){
                st[j]=a;
                mp[a]=1;
                j++;
            }
            if(mp[b]==0){
                st[j]=b;
                mp[b]=1;
                j++;
            }
            adj[a].push_back(b);
        }
        cycle=0;
        for(int i=0;i<j;i++){
            if(!vis[st[i]]){
                dfs(st[i]);
            }
        }
        if(cycle==1) printf("Case %d: No\n",++tc);
        else printf("Case %d: Yes\n",++tc);
        mp.clear();
        adj.clear();
        vis.clear();
    }
}
