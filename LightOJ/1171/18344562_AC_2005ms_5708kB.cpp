#include<bits/stdc++.h>
using namespace std;
int fx[]={2,2,-2,-2,1,1,-1,-1};
int fy[]={1,-1,1,-1,2,-2,2,-2};

#define NIL 0
#define M 40010
#define INF INT_MAX
int m,n;
int pairU [M+1];
int pairV [M+1];
int dist [M+1];
vector<int>adj[M];

bool bfs(){
    queue<int> Q;
    for (int i=1; i<=m; i++){
        if (pairU[i]==NIL){
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        if (dist[u] < dist[NIL]){
            for (int i=0; i<adj[u].size(); ++i){
                int v = adj[u][i];
                if (dist[pairV[v]] == INF){
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

bool dfs(int u){
    if (u != NIL){
        for (int i=0; i<adj[u].size(); ++i){
            int v = adj[u][i];
            if (dist[pairV[v]] == dist[u]+1){
                if (dfs(pairV[v]) == true){
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}


// Returns size of maximum matching
int hopcroftKarp()
{
    // pairU[u] stores pair of u in matching where u
    // is a vertex on left side of Bipartite Graph.
    // If u doesn't have any pair, then pairU[u] is NIL
    //int pairU [m+1];
    // pairV[v] stores pair of v in matching. If v
    // doesn't have any pair, then pairU[v] is NIL
    //int pairV [n+1];
    // dist[u] stores distance of left side vertices
    // dist[u] is one more than dist[u'] if u is next
    // to u'in augmenting path
    //int dist [m+1];
    // Initialize NIL as pair of all vertices
    for (int u=1; u<=m; u++) pairU[u] = NIL;
    for (int v=1; v<=n; v++) pairV[v] = NIL;
    // Initialize result
    int result = 0;
    // Keep updating the result while there is an
    // augmenting path.
    while (bfs()){
        // Find a free vertex
        for (int u=1; u<=m; u++)
            // If current vertex is free and there is
            // an augmenting path from current vertex
            if (pairU[u]==NIL && dfs(u))result++;
    }
    for(int i=0;i<M;i++)adj[i].clear();
    return result;
}


int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int p,q,r;
        scanf("%d %d %d",&p,&q,&r);
        n=m=(p*q)-r;
        int br[p+1][q+1];
        memset(br,0,sizeof br);
        for(int i=0;i<r;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            br[x][y]=-1;
        }
        int cnt=0;
        for(int i=1;i<=p;i++){
            for(int j=1;j<=q;j++){
                if(br[i][j]==0){
                    br[i][j]=++cnt;
                }
            }
        }
        for(int i=1;i<=p;i++){
            //cout<<i<<endl;
            for(int j=1;j<=q;j++){
                if(br[i][j]<0) continue;
                //if(i==row && j>col) break;
                // cout<<br[i][j]<<" ";
                for(int k=0;k<8;k++){
                    int x=i+fx[k];
                    int y=j+fy[k];
                    if(x<=p && x>=1 && y<=q && y>=1 && br[x][y]>0 ){
                        //cout<<br[i][j]<<" "<<br[x][y]<<endl;
                        //cout<<br[i][j]<<" "<<br[x][y]<<endl;

                            adj[br[i][j]].push_back(br[x][y]);
                            //adj[br[x][y]].push_back(br[i][j]);

                    }
                }
            }
            //cout<<endl;
        }
        //cout<<hopcroftKarp()<<endl;
        printf("Case %d: %d\n",++tc,n-hopcroftKarp()/2);
    }
}
