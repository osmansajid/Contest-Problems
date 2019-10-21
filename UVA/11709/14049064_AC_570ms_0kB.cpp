#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define white 0
#define grey  1
#define black 2

map<string,int>mp;
vector<int>adj[N];
stack<int>st;
int disc[N],low[N],vis[N],n,m,ans;

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
            if(tmp==u)break;
        }
        ans++;
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
    for(int i=0;i<n;i++)adj[i].clear();
}


int main()
{
    while(cin>>n>>m){
        if(n==0 && m==0) break;
        ans=0;
        getchar();
        for(int i=0;i<n;i++){
            string s;
            getline(cin,s);
            mp[s]=i;
        }
        for(int i=0;i<m;i++){
            string u,v;
            getline(cin,u);
            getline(cin,v);
            adj[mp[u]].push_back(mp[v]);
        }
        SCC();
        cout<<ans<<endl;
    }
}
