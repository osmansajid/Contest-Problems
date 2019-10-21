#include<bits/stdc++.h>
using namespace std;
map<int ,vector<int> > adj;
int vis[100010];
void dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<adj[s].size();i++)
    {
        int v=adj[s][i];
        if(!vis[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    int t,tc=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,counter=0;
        memset(vis,0,sizeof vis);
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                counter++;
            }
        }
        printf("%d\n",counter);
        adj.clear();
    }
}
