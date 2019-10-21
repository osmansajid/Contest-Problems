#include<bits/stdc++.h>
using namespace std;
#define N 100005
int vis[N];
vector<int>adj[N];

void dfs(int u){
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main()
{
    //freopen("out.txt","w",stdout);
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,m,cnt=0;
        stack<int>st;
        memset(vis,0,sizeof vis);
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i);
                st.push(i);
            }
        }
        memset(vis,0,sizeof vis);
        while(!st.empty()){
            int v=st.top();
            if(!vis[v]){
                dfs(v);
                cnt++;
            }
            st.pop();
        }
        printf("%d\n",cnt);
        for(int i=0;i<=n;i++) adj[i].clear();
    }
}
