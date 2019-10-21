#include<bits/stdc++.h>
using namespace std;
map<int , vector<int> > adj;
int vis[2010],color[2010],bug;
void dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<adj[s].size();i++)
    {
        int v=adj[s][i];
        if(!vis[v])
        {
            color[v]=1-color[s];
            dfs(v);
        }
        else if(color[v]!=(1-color[s]))
        {
            bug=1;
        }
    }
}
int main()
{
    int t,tc=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        bug=0;
        memset(vis,0,sizeof vis);
        memset(color,0,sizeof color);
        scanf("%d %d",&n,&m);
        int k=0;
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
           dfs(i);
        }
        if(bug==1)
        {
            printf("Scenario #%d:\n",tc++);
            printf("Suspicious bugs found!");
        }
        else
        {
            printf("Scenario #%d:\n",tc++);
            printf("No suspicious bugs found!");
        }
        if(t!=0)
        {
            printf("\n");
        }
        adj.clear();
    }
}
