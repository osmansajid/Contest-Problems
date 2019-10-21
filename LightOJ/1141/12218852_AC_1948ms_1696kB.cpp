#include<bits/stdc++.h>
using namespace std;
int vis[1100],d[1100];
map<int, vector<int> > adj;

int bfs(int s,int f)
{
    d[s]=0;
    vis[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        for(int i=2;i<=u/2 && u<=f;i++){
            int f=0;
            for(int j=2;j<=i/2;j++){
                if(i%j==0){
                    f=1;
                    break;
                }
            }
            if(u%i==0 && f==0){
                int v=i+u;
                if(!vis[v]){
                    vis[v]=1;
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        q.pop();
    }
    return d[f];
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof vis);
        memset(d,-1,sizeof d);
        int n,m;
        vector<int> p;
        scanf("%d %d",&n,&m);
        printf("Case %d: %d\n",++tc,bfs(n,m));
        adj.clear();
    }
}
