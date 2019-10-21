#include<bits/stdc++.h>
using namespace std;
map<int, vector<int> > adj;
map<int, map<int,int> > cost;
int vis[510],d[510];

void bfs(int s)
{
    vis[s]=1;
    d[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(vis[v]==0){
                d[v]=max(d[u],cost[u][v]);
                vis[v]=1;
                q.push(v);
            }
            else{
                int x=max(d[u],cost[u][v]);
                if(d[v]>x){
                    d[v]=x;
                    q.push(v);
                }
            }
        }
        q.pop();
    }
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof vis);
        memset(d,0,sizeof d);
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(cost[a][b]>c || cost[a][b]==0){
                cost[a][b]=c;
                cost[b][a]=c;
            }
        }
        int s;
        scanf("%d",&s);
        bfs(s);
        printf("Case %d:\n",++tc);
        for(int i=0;i<n;i++){
            if(vis[i])printf("%d\n",d[i]);
            else printf("Impossible\n");
        }
        adj.clear();
        cost.clear();
    }
}
