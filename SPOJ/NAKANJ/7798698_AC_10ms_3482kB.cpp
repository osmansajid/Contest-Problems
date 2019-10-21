#include<bits/stdc++.h>
using namespace std;
#define pa pair < int ,int >
int vis[10][10],level[10][10];
int fx[] ={1,2,-1,-2,-2,-1,1,2};
int fy[] ={2,1,2,1,-1,-2,-2,-1};
int chess(int x, int y, int r, int s)
{
    queue < pa > q;
    vis[x][y]=1;
    level[x][y]=0;
    pa p;
    p.first=x;
    p.second=y;
    q.push(p);
    while(!q.empty())
    {
        pa u;
        u=q.front();
        for(int i=0;i<8;i++)
        {
            pa v;
            v.first=u.first+fx[i];
            v.second=u.second+fy[i];
            if(v.first>=1 && v.first<=8 && v.second>=1 && v.second <=8 && !vis[v.first][v.second])
            {
                vis[v.first][v.second]=1;
                level[v.first][v.second]=level[u.first][u.second]+1;
                //cout<<level[v.first][v.second]<<endl;
                q.push(v);
                if(v.first==r && v.second==s)
                {
                    return level[v.first][v.second];
                }
            }
        }
        q.pop();
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof vis);
        memset(level,0,sizeof level);
        string a,b;
        cin>>a>>b;
        int m,n,p,q,ans;
        m=a[0]-'a'+1;
        n=a[1]-'0';
        p=b[0]-'a'+1;
        q=b[1]-'0';
        ans=chess(m,n,p,q);
        cout<<ans<<endl;
    }
}
