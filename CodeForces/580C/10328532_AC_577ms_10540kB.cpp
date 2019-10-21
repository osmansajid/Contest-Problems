#include<bits/stdc++.h>
using namespace std;
int vis[100010],l[100010],d[100010],c[100010],mc[100010];
map<int ,vector<int > > adj;

void bfs(int s)
{
    vis[s]=1;
    mc[s]=c[s]=d[s];
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        int f=0;
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(!vis[v]){
                f=1;
                vis[v]=1;
                if(d[u]!=0 && d[v]!=0){
                    c[v]=c[u]+d[v];
                    mc[v]=max(mc[u],c[v]);
                }
                else {
                    c[v]=d[v];
                    mc[v]=max(mc[u],c[v]);
                }
                q.push(v);
            }
        }
        if(f==0) l[u]=1;
        q.pop();
    }
}

int main()
{
    memset(vis,0,sizeof vis);
    memset(mc,0,sizeof mc);
    memset(d,0,sizeof d);
    memset(l,0,sizeof l);
    memset(c,0,sizeof c);
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        if(l[i]==1){
            if(mc[i]<=m) cnt++;
        }
    }
    cout<<cnt<<endl;
}
