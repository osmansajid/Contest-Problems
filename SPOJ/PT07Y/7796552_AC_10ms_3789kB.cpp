#include<bits/stdc++.h>
using namespace std;
int vis[10010];
vector<int> adj[20010];
int counter;
int flag=0;
void dfs(int u){
    vis[u] = 1;
    for(int i = 0 ; i< adj[u].size() ; i++){
           int v = adj[u][i];
           if(!vis[v]){
               dfs(v);
           }
           else
           {
               vis[v]++;
           }
    }
}
int main()
{
    int n,e,flag=0;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
          int a,b;
          cin>>a>>b;
          adj[a].push_back(b);
    }
    if(e!=n-1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
          dfs(1);
          for(int i=1;i<=n;i++)
          {
              if(vis[i]!=1)
              {
                  flag=1;
                  break;
              }
          }
          if(flag==0)
          {
              cout<<"YES"<<endl;
          }
          else
          {
              cout<<"NO"<<endl;
          }

    }
}
