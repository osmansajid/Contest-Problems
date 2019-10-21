#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >adj;
map<int,int>mrk;
vector<int> v;
int color[20010],vis[20010];
queue<int>q;
int bfs(int s)
{
    int count1=0,count2=0;
    vis[s]=1;
    q.push(s);
    color[s]=1;
    count2++;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(!vis[v])
            {
                if(color[u]==1)
                {
                    color[v]=2;
                    count1++;
                }
                else
                {
                    color[v]=1;
                    count2++;
                }
                q.push(v);
                vis[v]=1;
            }
        }
        q.pop();
    }
    return max(count1,count2);
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,p,count1=0,count2=0,ans=0;
       //freopen("E://c//in.txt","rt",stdin);
       //freopen("E://c//out.txt","wt",stdout);
        memset(color,0,sizeof color);
        memset(vis,0,sizeof vis);
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(mrk[a]==0)
                v.push_back(a);
                mrk[a]=1;
            if(mrk[b]==0)
                v.push_back(b);
                mrk[b]=1;
        }
        for(int j=0;j<v.size();j++)
        {
            if(!vis[v[j]])
            {
                ans+=bfs(v[j]);
            }
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
        adj.clear();
        mrk.clear();
        v.clear();
    }
    return 0;
}
