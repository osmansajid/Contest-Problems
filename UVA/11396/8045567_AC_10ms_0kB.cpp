#include<bits/stdc++.h>
using namespace std;
int flag;
int vis[400],color[400];
map<int , vector<int > > adj;
void dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<adj[s].size();i++)
    {
        int u=adj[s][i];
        if(!vis[u])
        {
            color[u]=1-color[s];
            dfs(u);
        }
        else if(color[u]!=1-color[s])
        {
            flag=1;
        }
    }
}
int main()
{
    int n,tc=0;
    while(cin>>n)
    {
        if(n==0) break;
        flag=0;
        memset(vis,0,sizeof vis);
        memset(color,0,sizeof color);
        int a,b;
        while(cin>>a>>b)
        {
            if(a==0 && b==0) break;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                if(flag==1) break;
            }
        }
        if(flag==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        adj.clear();
    }
    return 0;
}
