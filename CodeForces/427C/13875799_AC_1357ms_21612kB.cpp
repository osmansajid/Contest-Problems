#include<bits/stdc++.h>
using namespace std;

#define N 100010
#define white 0
#define grey  1
#define black 2
#define MAX 1e17
#define MOD 1e9

vector<long long>adj[N];
stack<long long>st;
long long a[N],disc[N],low[N],vis[N],ans=0,n,m;
long long ways=1;

void DFSSCC(int u){
    static int time=0;
    vis[u]=grey;
    st.push(u);
    low[u]=disc[u]=time++;
    for(int i=0;i<adj[u].size();i++){
        long long v=adj[u][i];
        if(vis[v]==white){
            DFSSCC(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]==grey){
            low[u]=min(low[u],disc[v]);
        }
    }
    if(low[u]==disc[u]){
        vector<long long>comp;
        long long mini=MAX;
        long long cnt=0;
        while(1){
            int tmp=st.top();
            st.pop();
            vis[tmp]=black;
            comp.push_back(tmp);
            if(tmp==u)break;
        }
        for(int i=0;i<comp.size();i++){
            mini=min(mini,a[comp[i]]);
        }
        for(int i=0;i<comp.size();i++){
            if(a[comp[i]]==mini){
                cnt++;
            }
        }
        ways=((ways%1000000007)*(cnt%1000000007))%1000000007;
        ans+=mini;
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
    for(int i=0;i<=n;i++)adj[i].clear();
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        long long a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    SCC();
    cout<<ans<<" "<<ways<<endl;
}
