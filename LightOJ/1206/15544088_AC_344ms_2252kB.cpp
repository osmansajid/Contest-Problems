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
int x1[M+1],x2[M+1],yy1[M+1],y2[M+1];
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
            if (pairU[i]==NIL && dfs(i))result++;
        }
    }
    return result;
}

bool later(string s1,string s2,int i,int j){
    int hour1=(s1[0]-'0')*10+(s1[1]-'0');
    int minu1=(s1[3]-'0')*10+(s1[4]-'0');
    int hour2=(s2[0]-'0')*10+(s2[1]-'0');
    int minu2=(s2[3]-'0')*10+(s2[4]-'0');
    int frstm=minu1+hour1*60+abs(x1[i]-x2[i])+abs(yy1[i]-y2[i])+abs(x2[i]-x1[j])+abs(y2[i]-yy1[j]);
    int scndm=minu2+hour2*60;
    if(frstm<scndm) return true;
    return false;
}

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        memset(x1,0,sizeof x1);
        memset(x2,0,sizeof x2);
        memset(yy1,0,sizeof yy1);
        memset(y2,0,sizeof y2);
        int cnt=0;
        for(int i=0;i<501;i++) adj[i].clear();
        cin>>m;
        string s[m+10];
        //int dis[m+10];
        for(int i=0;i<m;i++){

            cin>>s[i]>>x1[i]>>yy1[i]>>x2[i]>>y2[i];
            //dis[i]=abs(x1-x2)+abs(y1-y2);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(later(s[i],s[j],i,j)){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        hopcroftKarp();
        for(int i=1;i<=m;i++){
            if(pairV[i]==NIL) cnt++;
        }

        cout<<"Case "<<++tc<<": "<<cnt<<endl;
    }
}
