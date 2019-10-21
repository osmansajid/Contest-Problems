#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> > adj;
int vis[15][15],d[15][15],k,n;
int fx[4]={0,0,1,-1};
int fy[4]={-1,1,0,0};
char a[15][15];

bool check(int x,int y){
    if(x<n && x>=0 && y<n && y>=0 && a[x][y]!='#') return true;
    return false;
}

int bfs(int x,int y)
{
    memset(d,0,sizeof d);
    int posx=-1,posy=-1;
    d[x][y]=0;
    queue<pair<int,int> > q;
    pair<int,int> pi;
    pi.first=x;
    pi.second=y;
    q.push(pi);
    while(!q.empty()){
        pair<int,int> u=q.front();
        for(int i=0;i<4;i++){
            int xx=u.first+fx[i];
            int yy=u.second+fy[i];
            if(check(xx,yy) && (a[xx][yy]=='.'||a[xx][yy]<=a[x][y]+1)){
                if(d[xx][yy]>d[u.first][u.second]+1 || d[xx][yy]==0){
                    if(a[xx][yy]==a[x][y]+1){
                        posx=xx;
                        posy=yy;
                    }
                    d[xx][yy]=d[u.first][u.second]+1;
                    pair<int,int> v;
                    v.first=xx;
                    v.second=yy;
                    q.push(v);
                }
            }
        }
        q.pop();
    }
    if(posx!=-1)return d[posx][posy];
    return -1;
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        k=0;
        scanf("%d",&n);
        getchar();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%c",&a[i][j]);
                if(a[i][j]>='A' && a[i][j]<='Z')k++;
            }
            getchar();
        }
        int res=0,flag=0;
        for(int l=0;l<k-1;l++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(a[i][j]=='A'+l){
                        int w=bfs(i,j);
                        if(w==-1){
                            flag=1;
                            break;
                        }
                        res+=w;
                    }
                }
            }
        }
        if(flag==1) printf("Case %d: Impossible\n",++tc);
        else printf("Case %d: %d\n",++tc,res);
        adj.clear();
    }
}
