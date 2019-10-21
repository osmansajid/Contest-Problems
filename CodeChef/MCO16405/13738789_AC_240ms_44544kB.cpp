#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define white 0
#define grey  1
#define black 2

map<int,vector<int> > adj,adj2;
map<pair<int,int>,int>mp;
stack<int>st;
int disc[N],low[N],vis[N],id[N],n,m,com;
long long cost[N],tcost[N],ans[N];

long long dfs(int s){
    ans[s]=tcost[s];
    vis[s]=1;
    long long maxi=0;
    for(int i=0;i<adj2[s].size();i++){
        int v=adj2[s][i];
        if(!vis[v]){
            maxi=max(maxi,dfs(v));
        }
        else{
            maxi=max(maxi,ans[v]);
        }
    }
    ans[s]+=maxi;
    return ans[s];
}

void DFSSCC(int u){
    vis[u]=grey;
    st.push(u);
    static int time=0;
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
        com++;
        vector<int> compo;
        long long tot=0;
        while(1){
            int tmp=st.top();
            st.pop();
            vis[tmp]=black;
            compo.push_back(tmp);
            tot+=cost[tmp];
            if(tmp==u)break;
        }
        for(int i=0;i<compo.size();i++){
            id[compo[i]]=com;
        }
       // cout<<com<<" "<<tcost<<endl;
        tcost[com]=tot;
    }
}

void SCC(){
    memset(disc,0,sizeof disc);
    memset(low,0,sizeof low);
    memset(vis,0,sizeof vis);
    while(!st.empty()) st.pop();
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            DFSSCC(i);
        }
    }
}

int main()
{
    //int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    SCC();
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
            int u=id[i];
            int v=id[adj[i][j]];
            if(mp[make_pair(u,v)]==0 && u!=v){
                mp[make_pair(u,v)]=1;
                adj2[u].push_back(v);
            }
        }
    }
    for(int i=1;i<=com;i++)if(!vis[i])dfs(i);
    for(int i=1;i<=n;i++){
        cout<<ans[id[i]]<<" ";
    }
    adj.clear();
    memset(cost,0,sizeof cost);
    cout<<endl;
}
