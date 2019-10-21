#include<bits/stdc++.h>
using namespace std;

#define N 10001
#define INF INT_MAX
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

//this array is for storing minimum cost needed for going to a particular node

vector<long long> dijkastra(vector<pair<long long,long long> > adj[],long long s,long long n)
{
    vector<long long>d(n+1);
    for(long long i=1;i<=n;i++)
    {
        d[i]=INF;//initializing all the values by an infinite term
    }
    priority_queue<Node> pq;//priority queue
    pq.push(Node(s,0));//pushed both node and its distance cost
    //parent[s]=-1;//source parent is initialized as -1 as it is root
    d[s]=0;//source distance is 0
    while(!pq.empty())
    {
        Node u=pq.top();
        for(long long i=0;i<adj[u.str].size();i++)
        {
            long long v=adj[u.str][i].first;
            long long cost=adj[u.str][i].second;
            if(d[v]>d[u.str]+cost)//"relaxing"/updating
            {
                d[v]=d[u.str]+cost;
                pq.push(Node(v,d[v]));
                //parent[v]=u.str;
            }
        }
        pq.pop();
    }
    return d;
}



int main()
{
    long long t,tc=0;
    scanf("%lld",&t);
    while(t--){
        //for(long long i=0;i<N;i++)adj[i].clear();
        long long n,m,src,des,p;
        scanf("%lld %lld %lld %lld %lld",&n,&m,&src,&des,&p);
        //long long ans[n+1];
        vector<pair<long long,long long> > adj[n+1],adj2[n+1];
        vector<pair<pair<long long,long long>,long long> > edge;
        for(long long i=0;i<m;i++){
            long long u,v,c;
            scanf("%lld %lld %lld",&u,&v,&c);
            adj[u].push_back(make_pair(v,c));
            adj2[v].push_back(make_pair(u,c));
            edge.push_back(make_pair(make_pair(u,v),c));
            //adj[v].push_back(u);
            //cost[u][v]=min(c,cost[u][v]);
            //cost[v][u]=min(c,cost[v][u]);
        }
        //cout<<adj[5].size()<<endl;
        vector<long long> ans1=dijkastra(adj,src,n);
        vector<long long> ans2=dijkastra(adj2,des,n);
        long long ans=-1;
        for(long long i=0;i<m;i++){
            long long u,v,c;
            u=edge[i].first.first;
            v=edge[i].first.second;
            c=edge[i].second;
            if(ans1[u]+c+ans2[v]<=p){
                ans=max(ans,c);
            }
        }

        printf("Case %lld: %lld\n",++tc,ans);

    }
}
