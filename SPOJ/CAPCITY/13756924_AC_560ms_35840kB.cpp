#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define white 0
#define grey  1
#define black 2

vector<int> adj[N],adj2[N];
map<pair<int,int>,int>mp;
stack<int>st;
int disc[N],low[N],vis[N],id[N],dp[N],n,m,cm;

int dfs(int s){
    if(vis[s])return dp[s];
    vis[s]=1;
    int ret=1;
    for(int i=0;i<adj2[s].size();i++){
        int v=adj2[s][i];
        if(vis[v]==0){
            ret+=dfs(v);
        }
        else{
            ret+=dp[v];
        }
    }
    return dp[s]=ret;
}

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
        while(1){
            int tmp=st.top();
            st.pop();
            vis[tmp]=black;
            id[tmp]=cm;
            //comp[cm].push_back(tmp);
            if(tmp==u)break;
        }
        cm++;
    }
}

void SCC(){
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            DFSSCC(i);
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);  cin.tie(0);
    int ans=-1;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[b].push_back(a);
    }
    SCC();
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
            int v=adj[i][j];
            if(mp[make_pair(id[i],id[v])]==0 && id[i]!=id[v]){
                mp[make_pair(id[i],id[v])]=1;
                adj2[id[i]].push_back(id[v]);
                //cout<<id[i]<<" "<<id[v]<<endl;
            }
        }
    }
    vector<int>comp;
    for(int i=1;i<=n;i++){
        if(dfs(id[i])==cm){
            comp.push_back(i);
        }
    }
    printf("%d\n",comp.size());
    for(int i=0;i<comp.size();i++){
        printf("%d ",comp[i]);
    }
    printf("\n");
}
