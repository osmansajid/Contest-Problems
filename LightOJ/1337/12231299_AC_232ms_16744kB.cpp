#include<bits/stdc++.h>
using namespace std;
char g[510][510];
int m,n,vis[510][510],p[510][510],val[300000];
int fx[4]={0,0,-1,1};
int fy[4]={1,-1,0,0};


bool check(int x,int y){
    if(x<=n && x>0 && y<=m && y>0 && g[x][y]!='#') return true;
    return false;
}

int dfs(int x,int y)
{
    vis[x][y]=1;
    int res=0;
    if(g[x][y]=='C') res++;
    for(int i=0;i<4;i++){
        int xx=x+fx[i];
        int yy=y+fy[i];
        if(check(xx,yy)==1 && vis[xx][yy]==0){
            p[xx][yy]=p[x][y];
            res+=dfs(xx,yy);
        }
    }
    return res;
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        printf("Case %d:\n",++tc);
        memset(p,0,sizeof p);
        memset(vis,0,sizeof vis);
        memset(val,0,sizeof val);
        int q;
        scanf("%d %d %d",&n,&m,&q);
        getchar();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%c",&g[i][j]);
            }
            getchar();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!vis[i][j] && g[i][j]!='#'){
                    p[i][j]=((i-1)*m)+j;
                    val[p[i][j]]=dfs(i,j);
                }
            }
        }
        while(q--){
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%d\n",val[p[l][r]]);
        }
    }
}
