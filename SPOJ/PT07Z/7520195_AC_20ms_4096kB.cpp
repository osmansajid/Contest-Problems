#include<bits/stdc++.h>
using namespace std;
map<int, vector<int > > adj;
int vis[10010],level[10010],maxxx=0;
int bfs(int s)
{
    int r;
    queue<int> q;
    q.push(s);
    vis[s]=1;
    level[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
                level[v]=level[u]+1;
                if(level[v]>maxxx)
                {
                    maxxx=level[v];
                    r=v;
                }
            }
        }
        q.pop();
    }
    return r;
}
int bbfs(int s)
{
    int r;
    queue<int> q;
    q.push(s);
    vis[s]=1;
    level[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
                level[v]=level[u]+1;
                if(level[v]>maxxx)
                {
                    maxxx=level[v];
                }
            }
        }
        q.pop();
    }
    return maxxx;
}
int main()
{
    int n,maxx=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k=bfs(1);
    memset(vis,0,sizeof vis);
    memset(level,0,sizeof level);
    maxx=bbfs(k);
    printf("%d\n",maxx);
}
