#include<bits/stdc++.h>
using namespace std;
int vis[210][210];
int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};
char a[210][210];
int dis[210][210];
int f[210][210];
int n,m,counter;
queue<pair<int, int> > q;


void bfsf(int n,int m)
{
    memset(vis,0,sizeof vis);
    pair<int ,int > pi;
    while(!q.empty())
    {
        pi=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=pi.first+fx[i];
            int yy=pi.second+fy[i];
            //cout<<xx<<" "<<yy<<" "<<n<<" "<<m<<endl;
            if(xx>=0 && xx<n && yy>=0 && yy<m && vis[xx][yy]==0 && (a[xx][yy]=='.'||a[xx][yy]=='J'))
            {
                vis[xx][yy]=1;
                f[xx][yy]=min(f[xx][yy],f[pi.first][pi.second]+1);
                //cout<<xx<<" "<<yy<<f[xx][yy]<<endl;
                q.push(make_pair(xx,yy));
            }
        }
    }
}

int bfsj(int x,int y,int n,int m)
{
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    vis[x][y]=1;
    dis[x][y]=1;
    pair<int,int> pi;
    queue<pair<int,int> >pq;
    pq.push(make_pair(x,y));
    if(x==n-1 || y==m-1 || x==0 || y==0) return dis[x][y];
    while(!pq.empty())
    {
        pi=pq.front();
        pq.pop();
        for(int i=0;i<4;i++)
        {
            int xx=pi.first+fx[i];
            int yy=pi.second+fy[i];
            if(xx>=0 && xx<n && yy>=0 && yy<m && vis[xx][yy]==0 && a[xx][yy]!='#')
            {
                vis[xx][yy]=1;
                dis[xx][yy]=dis[pi.first][pi.second]+1;
                if(f[xx][yy]>dis[xx][yy])
                {
                   // cout<<f[xx][yy]<<" "<<dis[xx][yy]<<" "<<xx<<" "<<yy<<endl;
                    pq.push(make_pair(xx,yy));
                    if(xx==n-1 || yy==m-1 || xx==0 || yy==0) return dis[xx][yy];
                }
            }
        }
    }
    return 0;
}


int main()
{
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        int n,m,jx,jy;
        cin>>n>>m;
        memset(a,'\0',sizeof a);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
            getchar();
        }
        for(int i=0;i<210;i++)
        {
            for(int j=0;j<210;j++)
            {
                f[i][j]=999999;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='F')
                {
                    q.push(make_pair(i,j));
                    f[i][j]=1;
                }
                else if(a[i][j]=='J')
                {
                    jx=i;
                    jy=j;
                }
            }
        }
        bfsf(n,m);
        int ans;
        ans=bfsj(jx,jy,n,m);
        if(ans==0) cout<<"Case "<<++tc<<": IMPOSSIBLE"<<endl;
        else cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
}
