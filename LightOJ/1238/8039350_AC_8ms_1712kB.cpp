#include<bits/stdc++.h>
using namespace std;
int vis[50][50];
int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};
char a[50][50];
int dis[50][50];
int n,m,counter;
int bfs(int x,int y,int n,int m)
{
    vis[x][y]=1;
    dis[x][y]=0;
    pair<int ,int > pi;
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        pi=q.front();
       // cout<<pi.first<<" "<<pi.second<<endl;
        for(int i=0;i<4;i++)
        {
          int xx=pi.first+fx[i];
          int yy=pi.second+fy[i];
          //cout<<"nn "<<xx<<" "<<yy<<endl;
          if(xx>=0 && xx<n && yy>=0 && yy<m && vis[xx][yy]==0 &&( a[xx][yy]=='.' || a[xx][yy]=='h' || a[xx][yy]=='a' || a[xx][yy]=='b' || a[xx][yy]=='c'))
          {
              vis[xx][yy]=1;
              dis[xx][yy]=dis[pi.first][pi.second]+1;
              q.push(make_pair(xx,yy));
              if(a[xx][yy]=='h')
              {
                  return dis[xx][yy];
              }
          }

        }
        q.pop();
    }
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--)
    {
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
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='a'||a[i][j]=='b'||a[i][j]=='c')
                {
                    counter=0;
                    int x=bfs(i,j,n,m);
                    if(x>maxi)
                    {
                        maxi=x;
                    }
                    memset(vis,0,sizeof vis);
                }
            }
        }
        cout<<"Case "<<++tc<<": "<<maxi<<endl;
    }
}
