#include<bits/stdc++.h>
using namespace std;
int d[30010],d1[30010],vis[30010];
map<int,vector<int> > adj;
map<int,map<int,int> > cost;

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
            if(!vis[v]){
                vis[v]=1;
                d[v]=d[u]+cost[u][v];
                q.push(v);
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
        int n;
        scanf("%d",&n);
        for(int i=0;i<n-1;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            adj[a].push_back(b);
            adj[b].push_back(a);
            cost[a][b]=c;
            cost[b][a]=c;
        }
        memset(d,0,sizeof d);
        memset(d1,0,sizeof d1);
        memset(vis,0,sizeof vis);
        bfs(0);
        int mx=0,pos=0;
        for(int i=0;i<n;i++){
            if(mx<d[i]){
                mx=d[i];
                pos=i;
            }
        }
        memset(d,0,sizeof d);
        memset(vis,0,sizeof vis);
        bfs(pos);
        mx=0,pos=0;
        for(int i=0;i<n;i++){
            d1[i]=d[i];
        }
        for(int i=0;i<n;i++){
            if(mx<d[i]){
                mx=d[i];
                pos=i;
            }
        }
        memset(d,0,sizeof d);
        memset(vis,0,sizeof vis);
        bfs(pos);
        printf("Case %d:\n",++tc);
        for(int i=0;i<n;i++){
            printf("%d\n",max(d[i],d1[i]));
        }
        adj.clear();
        cost.clear();
    }
}
