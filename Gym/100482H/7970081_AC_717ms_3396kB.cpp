#include<bits/stdc++.h>
using namespace std;
int c;
map<int , vector<int > > adj;
map<int , int> mp;
stack<int> st;
int vis[100000];
int dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<adj[s].size();i++)
    {
        int u=adj[s][i];
        if(!vis[u])
        {
            c++;
            dfs(u);
            //vis[u]=c;
           // vis[s]=c;
        }
    }
    st.push(s);
    return c;
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        int n,m;
        memset(vis,0,sizeof vis);
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout<<"Case #"<<++tc<<":"<<endl;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                c=0;
                int m=dfs(i);
                while(!st.empty())
                {
                    vis[st.top()]=m;
                    st.pop();
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<vis[i];
            if(i!=n)
            {
                cout<<" ";
            }
        }
        cout<<endl;
        adj.clear();
    }
}
