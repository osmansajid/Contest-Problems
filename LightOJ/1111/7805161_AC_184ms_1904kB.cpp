#include<bits/stdc++.h>
using namespace std;
map<int ,vector<int> > adj;
int vis[10010],color[10010];
void bfs(int s)
{
    memset(vis,0,sizeof vis);
    vis[s]=1;
    queue<int> q;
    q.push(s);
    color[s]++;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                q.push(v);
                color[v]++;
            }
        }
        q.pop();
    }
}
int main()
{
    int t,tc=1;
    //freopen("E://c//in.txt","rt",stdin);
   // freopen("E://c//out.txt","wt",stdout);
    cin>>t;
    while(t--)
    {
        memset(color,0,sizeof color);
        int k,m,n,ans=0;
        cin>>k>>n>>m;
        int p[k+5];
        for(int i=0;i<k;i++)
        {
            cin>>p[i];
        }
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        for(int i=0;i<k;i++)
        {
            bfs(p[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(color[i]==k)
            {
                ans++;
            }
        }
        cout<<"Case "<<tc++<<": "<<ans<<endl;
        adj.clear();
    }
}
