#include<bits/stdc++.h>
using namespace std;
map<int , vector<int> > adj;
int vis[1000],color[1000];
int bicolor;
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
        else if(color[v]!=1-color[s])
        {
            bicolor=1;
        }
    }
}
int main()
{
    int n,e,i;
    while(cin>>n)
    {
        if(n==0)
        {
            return 0;
        }
        cin>>e;
        bicolor=0;
        memset(vis,0,1000);
        memset(color,0,1000);
        for(i=1;i<=e;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0);
        if(bicolor==1)
        {
            printf("NOT BICOLORABLE.\n");
        }
        else
        {
            printf("BICOLORABLE.\n");
        }
        adj.clear();
    }
}
