#include<bits/stdc++.h>
using namespace std;

struct node
{
    int nd,dist;
    node(int n,int d){
        nd=n;
        dist=d;
    }
};

bool operator<(node A,node B){
    return A.dist>B.dist;
}
map<int, vector<int> > adj;
int cost[1100][1100];
int p[1100];
int d[1100];

void dijkstra(int s,int n)
{
    for(int i=1;i<=n;i++){
        d[i]=INT_MAX;
    }
    priority_queue<node>pq;
    pq.push(node(s,0));
    p[s]=-1;
    d[s]=0;
    while(!pq.empty()){
        node u=pq.top();
        for(int i=0;i<adj[u.nd].size();i++){
            int v=adj[u.nd][i];
            if(d[v]>d[u.nd]+cost[u.nd][v]){
                d[v]=d[u.nd]+cost[u.nd][v];
                pq.push(node(v,d[v]));
                p[v]=u.nd;
            }
        }
        pq.pop();
    }
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(d,0,sizeof d);
        memset(p,0,sizeof p);
        memset(cost,-1,sizeof cost);
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(cost[a][b]==-1 || cost[a][b]>c){
                cost[a][b]=c;
                cost[b][a]=c;
            }
        }
        dijkstra(1,n);
        if(d[n]!=INT_MAX)printf("Case %d: %d\n",++tc,d[n]);
        else printf("Case %d: Impossible\n",++tc);
        adj.clear();
    }
}
