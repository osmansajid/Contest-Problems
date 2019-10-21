#include<bits/stdc++.h>
using namespace std;
#define N 10005
int vis[N],dis[N],low[N],parent[N],art[N];
vector<int> adj[N];

void cutV(int u){
    static int time=0;
    int children=0;
    vis[u]=1;
    dis[u]=low[u]=time++;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!vis[v]){
            parent[v]=u;
            children++;
            cutV(v);
            low[u]=min(low[v],low[u]);
            if(parent[u]==-1 && children>1){
                art[u]=1;
            }
            else if(parent[u]!=-1 && low[v]>=dis[u]){
                art[u]=1;
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],dis[v]);
        }
    }
}

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        memset(parent,-1,sizeof parent);
        memset(low,0,sizeof low);
        memset(dis,0,sizeof dis);
        memset(art,0,sizeof art);
        int n,m,cnt=0;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cutV(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(art[i]){
                cnt++;
            }
        }
        cout<<"Case "<<++tc<<": "<<cnt<<endl;
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
