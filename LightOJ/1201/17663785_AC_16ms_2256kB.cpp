#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define M 1010
#define INF INT_MAX
int m,n;
int pairU [M+1];
int pairV [M+1];
int dist [M+1];
list<int>adj[M+1];

// Returns true if there is an augmenting path, else returns
// false
bool bfs(){
    queue<int> Q; //an integer queue
    // First layer of vertices (set distance as 0)
    for (int u=1; u<=m; u++){
        // If this is a free vertex, add it to queue
        if (pairU[u]==NIL){
            // u is not matched
            dist[u] = 0;
            Q.push(u);
        }
        // Else set distance as infinite so that this vertex
        // is considered next time
        else dist[u] = INF;
    }
    // Initialize distance to NIL as infinite
    dist[NIL] = INF;
    // Q is going to contain vertices of left side only.
    while (!Q.empty()){
        // Dequeue a vertex
        int u = Q.front();
        Q.pop();
        // If this node is not NIL and can provide a shorter path to NIL
        if (dist[u] < dist[NIL]){
            // Get all adjacent vertices of the dequeued vertex u
            list<int>::iterator i;
            for (i=adj[u].begin(); i!=adj[u].end(); ++i){
                int v = *i;
                // If pair of v is not considered so far
                // (v, pairV[V]) is not yet explored edge.
                if (dist[pairV[v]] == INF){
                    // Consider the pair and add it to queue
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    // If we could come back to NIL using alternating path of distinct
    // vertices then there is an augmenting path
    return (dist[NIL] != INF);
}

// Returns true if there is an augmenting path beginning with free vertex u
bool dfs(int u){
    if (u != NIL){
        list<int>::iterator i;
        for (i=adj[u].begin(); i!=adj[u].end(); ++i){
            // Adjacent to u
            int v = *i;
            // Follow the distances set by BFS
            if (dist[pairV[v]] == dist[u]+1){
                // If dfs for pair of v also returns
                // true
                if (dfs(pairV[v]) == true){
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        // If there is no augmenting path beginning with u.
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
        int q;
        scanf("%d%d",&n,&q);
        m=n;
        while(q--){
            int a,b;
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //memset(mark,0,sizeof mark);
        int ret=hopcroftKarp()/2;
        //cout<<ret<<endl;
        printf("Case %d: %d\n",++tc,n-ret);
    }
}
