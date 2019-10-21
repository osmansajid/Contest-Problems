#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define white 0
#define grey  1
#define black 2

map<int,vector<int> >adj;
stack<int>st;
int disc[N],low[N],vis[N],id[N],n,m;

void DFSSCC(int u){
    static int time=0;
    vis[u]=grey;
    st.push(u);
    low[u]=disc[u]=time++;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(vis[v]==white){
            DFSSCC(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]==grey){
            low[u]=min(low[u],disc[v]);
        }
    }
    if(low[u]==disc[u]){
        vector<int>ans;
        int mini=INT_MAX;
        while(1){
            int tmp=st.top();
            st.pop();
            vis[tmp]=black;
            ans.push_back(tmp);
            mini=min(mini,tmp);
            if(tmp==u)break;
        }
        for(int i=0;i<ans.size();i++) id[ans[i]]=mini;
    }
}

void SCC(){
    memset(disc,0,sizeof disc);
    memset(low,0,sizeof low);
    memset(vis,0,sizeof vis);
    while(!st.empty()) st.pop();
    for(int i=0;i<n;i++){
        if(!vis[i]){
            DFSSCC(i);
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
    }
    SCC();
    for(int i=0;i<n;i++)printf("%d\n",id[i]);
    adj.clear();
}

