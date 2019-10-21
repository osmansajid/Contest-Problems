#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define M 55
#define INF INT_MAX
int m,n;
int pairU [M+1];
int pairV [M+1];
int dist [M+1];
vector<int>adj[M];
struct SET{
    int in,ag,di;
}setA [M+1],setB [M+1];

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

int hopcroftKarp(){
    //memset(dist,0,sizeof dist);
    for (int i=1; i<=m; i++) pairU[i] = NIL;
    for (int i=1; i<=n; i++) pairV[i] = NIL;
    int result = 0;
    while (bfs()){
        for (int i=1; i<=m; i++){
            if (pairU[i]==NIL && dfs(i))result++;
        }
    }
    return result;
}

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        for(int i=0;i<101;i++) adj[i].clear();
        cin>>m>>n;
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            setA[i].in=x;
            setA[i].ag=y;
            setA[i].di=z;
        }
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            setB[i].in=x;
            setB[i].ag=y;
            setB[i].di=z;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(abs(setA[i].ag-setB[j].ag)<=5 && abs(setA[i].in-setB[j].in)<=12 && setA[i].di==setB[j].di){
                    adj[i+1].push_back(j+1);
                   // adj[j+1].push_back(i+1);
                }
            }
        }
        cout<<"Case "<<++tc<<": "<<hopcroftKarp()<<endl;
    }
}
