#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define M 1005
#define INF INT_MAX

int adj[M][M],setA[M],setB[M];
stack<int>st;
int n,m,counter,id[M],vis[M];


bool bfs(int pairU[],int pairV[],int dist[]){
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
            for (int i=1; i<=n; ++i){
                if(adj[u][i]){
                    int v = i;
                    if (dist[pairV[v]] == INF){
                        dist[pairV[v]] = dist[u] + 1;
                        Q.push(pairV[v]);
                    }
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

bool dfs(int u,int pairU[],int pairV[],int dist[]){
    if (u != NIL){
        for (int i=1; i<=n; ++i){
            if(adj[u][i]){
                int v=i;
                if (dist[pairV[v]] == dist[u]+1){
                    if (dfs(pairV[v],pairU,pairV,dist) == true){
                        pairV[v] = u;
                        pairU[u] = v;
                        return true;
                    }
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroftKarp(){
    int pairU [M];
    int pairV [M];
    int dist [M];
    for (int i=1; i<=m; i++) pairU[i] = NIL;
    for (int i=1; i<=n; i++) pairV[i] = NIL;
    int result = 0;
    while (bfs(pairU,pairV,dist)){
        for (int i=1; i<=m; i++){
            if (pairU[i]==NIL && dfs(i,pairU,pairV,dist))result++;
        }
    }
    return result;
}


int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        memset(adj,0,sizeof adj);
        cin>>m;
        for(int i=0;i<m;i++) cin>>setA[i];
        cin>>n;
        for(int i=0;i<n;i++) cin>>setB[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(setB[i]%setA[j]==0){
                    adj[j+1][i+1]=1;
                    //adj[i+1].push_back(j+1);
                }
            }
        }
        cout<<"Case "<<++tc<<": "<<hopcroftKarp()<<endl;
    }
}
