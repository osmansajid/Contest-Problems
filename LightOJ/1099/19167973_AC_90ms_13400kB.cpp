#include<bits/stdc++.h>
using namespace std;
#define N 100001
 
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
vector<pair<int,long long> > adj[N];
long long d[N],d2[N],md[N];//this array is for storing minimum cost needed for going to a particular node
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
        d[i]=100000000000000;//initializing all the values by an infinite term
        d2[i]=100000000000000;
 
    }
    priority_queue<Node> pq;//priority queue
    pq.push(Node(s,0));//pushed both node and its distance cost
    parent[s]=-1;//source parent is initialized as -1 as it is root
    d[s]=0;//source distance is 0
   // best[s].push_back(0);
    while(!pq.empty())
    {
        Node u=pq.top();
        for(long long i=0;i<adj[u.str].size();i++)
        {
            long long v=adj[u.str][i].first;
            //cout<<u.str<<" "<<u.cost<<" "<<adj[u.str][i].first<<" "<<adj[u.str][i].second<<" "<<d[v]<<" "<<d2[v]<<endl;
            if(d[v]>u.cost+adj[u.str][i].second)//"relaxing"/updating
            {
                if(d[u.str]!=0) md[v]=min(md[u.str],adj[u.str][i].second);
                else md[v]=adj[u.str][i].second;
                d2[v]=d[v];
                d[v]=u.cost+adj[u.str][i].second;
                pq.push(Node(v,d[v]));
                parent[v]=u.str;
            }
            else if(d[v]==u.cost+adj[u.str][i].second){
                if(d[u.str]!=0) md[v]=min(md[u.str],adj[u.str][i].second);
                else md[v]=adj[u.str][i].second;
            }
            else if(d[v]<u.cost+adj[u.str][i].second && d2[v]>u.cost+adj[u.str][i].second){
                d2[v]=min(d2[v],u.cost+adj[u.str][i].second);
                pq.push(Node(v,d2[v]));
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
        int n,m;
        scanf("%d%d%",&n,&m);
        for(int i=1;i<=m;i++){
            int u,v;
            long long c;
            scanf("%d%d%lld",&u,&v,&c);
            adj[u].push_back(make_pair(v,c));
            adj[v].push_back(make_pair(u,c));
        }
        dijkastra(1,n);
        //cout<<d[n]<<endl;
        //sort(best[n].begin(),best[n].end());
        printf("Case %d: %lld\n",++tc,min(d[n]+2*md[n]!=0?d[n]+2*md[n]:d2[n],d2[n]));
        for(int i=0;i<N;i++) {
            adj[i].clear();
        }
    }
}