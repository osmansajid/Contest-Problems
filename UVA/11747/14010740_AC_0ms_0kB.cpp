#include<bits/stdc++.h>
using namespace std;
#define N 1005
vector<int>adj[N];
map<pair<int,int>,int>mark;
int vis[N],n,m;
int pr[N];


struct edge
{
  int u,v,w;//first node,second node,cost
};

vector<edge> e;

bool operator< (edge A,edge B)
{
    return A.w<B.w;
}

int find(int r)//finds parent of a node
{
    if(pr[r]==r)
    {
        return r;
    }
    else
    {
        return pr[r]=find(pr[r]);//path compression
    }
}
void kruskal_mst(int n)
{
    sort(e.begin(),e.end());
    for(int i=0;i<n;i++)
    {
        pr[i]=i;
    }
    int sz=e.size();
    long long counter=0;
    for(int i=0;i<sz;i++)
    {
        int u,v;
        u=find(e[i].u);
        v=find(e[i].v);
        //cout<<u<<" "<<v<<endl;
        if(u!=v)
        {
            pr[u]=v;
        }
        else{
            mark[make_pair(e[i].u,e[i].v)]=1;
            mark[make_pair(e[i].v,e[i].u)]=1;
        }
    }
}

int main()
{
    //freopen("out.txt","w",stdout);
    int tc=0;
    while(cin>>n>>m){
        if(n==0 && m==0) break;
        int flg=0;
        vector<edge> org;
        memset(vis,0,sizeof vis);
        for(int i=0;i<m;i++){
            edge x;
            cin>>x.u>>x.v>>x.w;
            e.push_back(x);
            org.push_back(x);
            adj[x.u].push_back(x.v);
            adj[x.v].push_back(x.u);
        }
        int cnt=0;
        kruskal_mst(n);
        for(int i=0;i<m;i++){
            if(mark[make_pair(org[i].u,org[i].v)]){
                if(cnt)cout<<" ";
                cout<<org[i].w;
                cnt++;
            }
        }
        if(!cnt)cout<<"forest";
        cout<<endl;
        mark.clear();
        for(int i=0;i<n;i++) adj[i].clear();
        e.clear();
    }
}
