#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define M 510
#define INF INT_MAX
int m,n;
int pairU [M+1];
int pairV [M+1];
int setA [M+1];
int setB [M+1];
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

int hopcroftKarp(){
    for (int i=1; i<=m; i++) pairU[i] = NIL;
    for (int i=1; i<=m; i++) pairV[i] = NIL;
    int result = 0;
    while (bfs()){
        for (int i=1; i<=m; i++){
            if (pairU[i]==NIL  && dfs(i))result++;
        }
    }
    return result;
}

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        memset(setA,0,sizeof setA);
        memset(setB,0,sizeof setB);
        for(int i=0;i<M;i++) adj[i].clear();
        int x,y,l=0,k=0;
        cin>>x>>y>>m;
        string s1[m+10],s2[m+10];
        for(int i=0;i<m;i++){
            cin>>s1[i]>>s2[i];
            if(s1[i][0]=='M'){
                setA[k]=i;
                k++;
            }
            else{
                setB[l]=i;
                l++;
            }
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<l;j++){
                if(s1[setA[i]]==s2[setB[j]] || s2[setA[i]]==s1[setB[j]]){
                    //cout<<i+1<<" "<<j+1<<endl;
                    adj[setA[i]+1].push_back(setB[j]+1);
                    //adj[j+1].push_back(i+1);
                }
            }
        }
        int ans=hopcroftKarp();
        cout<<"Case "<<++tc<<": "<<m-ans<<endl;
    }
}
