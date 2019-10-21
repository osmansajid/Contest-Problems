#include<bits/stdc++.h>
using namespace std;
map<int, vector<int> > adj;
map<int,map<int,int> > cost;
long long d[30010],vis[30010];

int bfs(int s)
{
    int ans=0;
    queue<int>q;
    vis[s]=1;
    d[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
                d[v]=d[u]+cost[u][v];
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
        bfs(0);
        long long mx=-1,pos;
        for(int i=0;i<n;i++){
            if(d[i]>mx){
                pos=i;
                mx=d[i];
            }
        }
        memset(d,0,sizeof d);
        memset(vis,0,sizeof vis);
        bfs(pos);
        long long mxx=-1;
        for(int i=0;i<n;i++){
            if(d[i]>mxx){
                mxx=d[i];
            }
        }
        printf("Case %d: %lld\n",++tc,mxx);
        adj.clear();
        cost.clear();
        memset(d,0,sizeof d);
        memset(vis,0,sizeof vis);
    }
}
