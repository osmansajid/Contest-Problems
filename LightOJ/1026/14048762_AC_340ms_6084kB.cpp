#include<bits/stdc++.h>
using namespace std;
#define N 10005
int vis[N],dis[N],low[N],parent[N];
vector<int> adj[N];
vector<pair<int,int> > ans;

void bridges(int u){
    static int time=0;
    vis[u]=1;
    dis[u]=low[u]=time++;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!vis[v]){
            parent[v]=u;
            bridges(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>dis[u]){
                ans.push_back(make_pair(min(u,v),max(u,v)));
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],dis[v]);
        }
    }
}

int main()
{
    //freopen("out.txt","w",stdout);
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof vis);
        memset(parent,-1,sizeof parent);
        memset(low,0,sizeof low);
        memset(dis,0,sizeof dis);
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int u,m=0;
            scanf("%d",&u);
            char s[100010];
            scanf("%s",s);
            for(int j=1;j<strlen(s)-1;j++){
                m=m*10+(s[j]-'0');
            }
            for(int j=0;j<m;j++){
                int v;
                scanf("%d",&v);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bridges(i);
            }
        }
        printf("Case %d:\n",++tc);
        printf("%d critical links\n",ans.size());
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            printf("%d - %d\n",ans[i].first,ans[i].second);
        }
        for(int i=0;i<n;i++) adj[i].clear();
        ans.clear();
    }
}
