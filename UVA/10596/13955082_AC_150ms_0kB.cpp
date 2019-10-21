#include<bits/stdc++.h>
using namespace std;
#define N 210

int n,m,x,vis[N];
vector<int> adj[N];

void dfs(int s){
    vis[s]=1;
    for(int i=0;i<adj[s].size();i++){
        int v=adj[s][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}

bool isConnected(){
    memset(vis,0,sizeof vis);
    int node=0;
    dfs(node);
    for(int i=0;i<n;i++){
        if(vis[i]==0 && adj[i].size()!=0){
            return false;
        }
    }
    return true;
}

int isEuler(){
    if(isConnected()){
        int odd=0;
        for(int i=0;i<n;i++){
            if(adj[i].size()%2!=0){
                odd++;
            }
        }
        if(odd>2) return 0;
        else if(odd)return 1;
        else return 2;
    }
    else{
        return 0;
    }
}
int main()
{
    while(cin>>n>>m){
        memset(vis,0,sizeof vis);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            x=a;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(m==0){
            printf("Not Possible\n");
        }
        else if(isEuler()==2){
            printf("Possible\n");
        }
        else{
            printf("Not Possible\n");
        }
        for(int i=0;i<n;i++) adj[i].clear();
    }
}

