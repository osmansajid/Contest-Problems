#include<bits/stdc++.h>
using namespace std;
map<int ,vector<int> > adj,radj;
int cost[110][110],vis[110];

int dfs(int s)
{
    vis[s]=1;
    int res=0;
    for(int i=0;i<adj[s].size();i++){
        int u=adj[s][i];
        if(!vis[u]){
            res+=dfs(u);
        }
        res+=cost[s][u];
    }
    return res;
}

int rdfs(int s)
{
    vis[s]=1;
    int res=0;
    for(int i=0;i<radj[s].size();i++){
        int u=radj[s][i];
        if(!vis[u]){
            res+=rdfs(u);
        }
        res+=cost[s][u];

    }
    return res;
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            cost[a][b]=0;
            cost[b][a]=c;
            if(adj[a].size()==0 && radj[b].size()==0){
                adj[a].push_back(b);
                radj[b].push_back(a);
            }
            else{
                adj[b].push_back(a);
                radj[a].push_back(b);
            }
        }
        memset(vis,0,sizeof vis);
        int res1=dfs(1);
        memset(vis,0,sizeof vis);
        int res2=rdfs(1);
        printf("Case %d: %d\n",++tc,min(res1,res2));
        adj.clear();
        radj.clear();
        memset(cost,0,sizeof cost);
    }
}
