#include<bits/stdc++.h>
using namespace std;
#define N 5010
#define white 0
#define grey  1
#define black 2

vector<int>adj[5010],ans;
stack<int>st;
int disc[N],low[N],vis[N],n,m;

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
        vector<int> compo;
        int ok[N];
        memset(ok,0,sizeof ok);
        bool no=true;
        while(1){
            int tmp=st.top();
            st.pop();
            vis[tmp]=black;
            compo.push_back(tmp);
            ok[tmp]=1;
            if(tmp==u)break;
        }
        for(int i=0;i<compo.size();i++){
            for(int j=0;j<adj[compo[i]].size();j++){
                int v=adj[compo[i]][j];
                if(!ok[v]) no=false;
            }
        }
        if(no){
            for(int i=0;i<compo.size();i++){
                ans.push_back(compo[i]);
            }
        }
    }
}

void SCC(){
    memset(disc,0,sizeof disc);
    memset(low,0,sizeof low);
    memset(vis,0,sizeof vis);
    ans.clear();
    while(!st.empty()) st.pop();
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            DFSSCC(i);
        }
    }
    for(int i=1;i<=n;i++)adj[i].clear();
}

int main()
{
    while(1){
        cin>>n;
        if(n==0)break;
        cin>>m;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        SCC();
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(i!=ans.size()-1)cout<<ans[i]<<" ";
            else cout<<ans[i];
        }
        cout<<endl;
    }
}

