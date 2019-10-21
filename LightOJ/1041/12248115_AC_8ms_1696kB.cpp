#include<bits/stdc++.h>
using namespace std;
map<string,int> id;

struct edge
{
  int u,v,w;//first node,second node,cost
};

bool operator< (edge A,edge B)
{
    return A.w<B.w;
}
vector<edge> e;
int pr[110];
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
long long kruskal_mst(int n)
{
    sort(e.begin(),e.end());//sorts edge vector e according to cost
    for(int i=1;i<=n;i++)
    {
        pr[i]=i;//makes each node its own parent
    }
    int sz=e.size();
    long long s=0,counter=0;
    for(int i=0;i<sz;i++)
    {
        int u,v;
        u=find(e[i].u);
        v=find(e[i].v);
        if(u!=v)//union
        {
            pr[u]=v;
            s+=e[i].w;
            counter++;
            if(counter==n-1)
            {
                break;
            }
        }
    }
    if(counter!=n-1) return -1;
    return s;//returns minimum cost
}


int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,i=1;
        string st[110];
        scanf("%d",&n);
        while(n--){
            string a,b;
            int c,fa=0,fb=0;
            cin>>a>>b>>c;
            if(id[a]==0){
                id[a]=i;
                i++;
            }
            if(id[b]==0){
                id[b]=i;
                i++;
            }
            edge x;
            x.u=id[a];
            x.v=id[b];
            x.w=c;
            e.push_back(x);
        }

        int ans=kruskal_mst(i-1);
        if(ans==-1) printf("Case %d: Impossible\n",++tc);
        else printf("Case %d: %d\n",++tc,ans);
        id.clear();
        e.clear();
    }
}

