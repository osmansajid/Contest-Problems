#include<bits/stdc++.h>
using namespace std;
#define ll             long long
#define sca(a)         scanf("%lld",&a);
#define scaa(a,b)      scanf("%lld %lld",&a,&b);
#define scaaa(a,b,c)   scanf("%lld %lld %lld",&a,&b,&c);
#define mp(a,b)        make_pair(a,b)
#define inf            1e17
#define N              100005
#define fori(i,n)      for(int i=0;i<n;i++)
#define pb(a)          push_back(a)

ll n,m,s,tt,v,d1[N],d2[N],d3[N];
vector<pair<ll,ll> > adj[N];


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


void dijkstra(ll s,ll n,ll d[])
{
    for(long long i=1;i<=n;i++){
        d[i]=inf;//initializing all the values by an infinite term
    }
    //cout<<s<<endl;
    priority_queue<Node> pq;//priority queue
    pq.push(Node(s,0));//pushed both node and its distance cost
    d[s]=0;//source distance is 0
    while(!pq.empty())
    {
        Node u=pq.top();
        for(long long i=0;i<adj[u.str].size();i++)
        {
            ll v=adj[u.str][i].second;
            if(d[v]>d[u.str]+adj[u.str][i].first){
                d[v]=d[u.str]+adj[u.str][i].first;
                pq.push(Node(v,d[v]));
            }
        }
        pq.pop();
    }

}

int main()
{
    //cout<<"L";
    //ll n,m,s,tt,v;
    ll t;
    sca(t);
    while(t--){
        scaa(n,m);
        scaaa(s,tt,v);
        fori(i,m){
            ll u,vv,w;
            scaaa(u,vv,w);
            adj[u].pb(mp(w,vv));
            adj[vv].pb(mp(w,u));
        }

        dijkstra(s,n,d1);
        dijkstra(v,n,d2);
        dijkstra(tt,n,d3);
        ll ans=inf;
        for(int i=1;i<=n;i++){
            ans=min(ans,d1[i]+d2[i]+d3[i]);
        }
        printf("%lld\n",ans);
        for(int i=0;i<=n;i++) adj[i].clear();
    }
}

