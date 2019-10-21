#include<bits/stdc++.h>
using namespace std;
int vis[110],level[110],dis[110];
map<int , vector<int> > adj;
void bfs(int s)
{
    memset(vis,0,sizeof vis);
    memset(level,0,sizeof level);
    queue<int> q;
    vis[s]=1;
    level[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                level[v]=level[u]+1;
                dis[v]+=level[v];
                q.push(v);
            }
        }
        q.pop();
    }
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        memset(dis,0,sizeof dis);
        int n,r;
        cin>>n>>r;
        for(int i=0;i<r;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int s,d,maxx=0;
        cin>>s>>d;
        bfs(s);
        bfs(d);
        for(int i=0;i<n;i++)
        {
            if(dis[i]>maxx)
            {
                maxx=dis[i];
            }
        }
        cout<<"Case "<<++tc<<": "<<maxx<<endl;
        adj.clear();
    }
}
