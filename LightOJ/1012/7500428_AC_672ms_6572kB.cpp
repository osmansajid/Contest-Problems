#include<bits/stdc++.h>
using namespace std;
int fx[] ={0,0,1,-1};
int fy[] ={-1,1,0,0};
int vis[1000][1000];
char a[1000][1000];
int r,c;
void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int xx= x+fx[i];
        int yy= y+fy[i];
        if(xx>=0 && xx<r && yy>=0 && yy<c && vis[xx][yy]==0 && a[xx][yy]=='.')
        {
            dfs(xx,yy);
        }
    }
}
int main()
{
    int t,i;
    char p;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        int j,k,count=0;
        cin>>c>>r;
        for(j=0;j<1000;j++)
        {
            for(k=0;k<1000;k++)
            {
                a[j][k]='\0';
                vis[j][k]=0;
            }
        }
        for(j=0;j<r;j++)
        {
            for(k=0;k<c;k++)
            {
                cin>>p;
                a[j][k]=p;
            }
        }
        for(j=0;j<r;j++)
        {
            for(k=0;k<c;k++)
            {
                if(a[j][k]=='@')
                {
                    dfs(j,k);
                }
            }
        }
        for(j=0;j<r;j++)
        {
            for(k=0;k<c;k++)
            {
                if(vis[j][k]!=0)
                {
                  count++;
                }
            }
        }
        printf("Case %d: ",i);
        cout<<count<<endl;
    }
  return 0;
}
