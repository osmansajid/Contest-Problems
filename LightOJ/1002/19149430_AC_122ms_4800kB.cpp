#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
#define N 510
#define INF 100000000000000
struct Node
{
    long long str,cost;
    Node(long long _str,long long _cost)
    {
        str=_str;
        cost=_cost;
    }
};
bool operator<(Node A,Node B)//operator overloading
{                            //priority queue returns the greatest value so we should write c
    return A.cost>B.cost;    //operator in a way so that cheapest value becomes the greatest value
}
vector<long long> adj[N];
long long cost[N][N];//cost of an edge
long long d[N];//this array is for storing minimum cost needed for going to a particular node
long long parent[N];//finding ancestors
void printpath(long long s)//this function prints shortest path from source
{
    if(parent[s]==-1)
    {
        cout<<s<<" ";
        return;
    }
    printpath(parent[s]);
    cout<<s<<" ";
}
void dijkastra(long long s,long long n)
{
    for(long long i=1;i<=n;i++)
    {
        d[i]=INF;//initializing all the values by an infinite term
    }
    priority_queue<Node> pq;//priority queue
    pq.push(Node(s,0));//pushed both node and its distance cost
    parent[s]=-1;//source parent is initialized as -1 as it is root
    d[s]=0;//source distance is 0
    while(!pq.empty())
    {
        Node u=pq.top();
        for(long long i=0;i<adj[u.str].size();i++)
        {
            long long v=adj[u.str][i];
            if(d[v]>max(d[u.str],cost[u.str][v]))//"relaxing"/updating
            {
                d[v]=max(d[u.str],cost[u.str][v]);
                pq.push(Node(v,d[v]));
                parent[v]=u.str;
            }
        }
        pq.pop();
    }
}



int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<N;i++){
            adj[i].clear();
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cost[i][j]=INF;
            }
        }
        long long n,m;
        scanf("%lld %lld",&n,&m);
        for(int i=0;i<m;i++){
            long long u,v,c;
            scanf("%lld %lld %lld",&u,&v,&c);
            u++;
            v++;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u][v]=min(c,cost[u][v]);
            cost[v][u]=min(c,cost[v][u]);
        }
        long long src;
        scanf("%lld",&src);
        dijkastra(src+1,n);
        printf("Case %d:\n",++tc);
        for(int i=1;i<=n;i++){
            if(d[i]!=INF)printf("%lld\n",d[i]);
            else printf("Impossible\n");
        }
    }
}
