#include<bits/stdc++.h>
using namespace std;
#define L long long
#define pll pair<long long,long long>

const L INF=(L)1<<60;
struct Edge{
	L from,to,cap,flow,cost;
	Edge(int from,int to,int cap,int flow,int cost):from(from),to(to),cap(cap),flow(flow),cost(cost) {}
};
const int N = 1010;

namespace mcmf{
	int n,m,s,t;
	vector<Edge> edges;
	vector<L> G[N];
	bool inq[N];
	L d[N],p[N],a[N];                     /// N = Size of nodes in flow network
	void init(int src,int sink,int node)
	{
		n=node;
		s= src;
		t = sink;
		edges.clear();
		for(int i=0;i<=n;++i) G[i].clear();
	}
	void addEdge(int from,int to,L cap,L cost)
	{
		edges.push_back(Edge(from,to,cap,0,cost));
		edges.push_back(Edge(to,from,0,0,-cost));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool spfa(L &flow,L& cost)
	{
		for(int i=0;i<=n;++i) d[i]=INF,inq[i]=0;
		queue<int> que;
		que.push(s);
		inq[s]=1;d[s]=0;p[s]=0;a[s]=INF;
		while(!que.empty())
		{
			int x=que.front();que.pop();
			inq[x]=0;
			for(int i=0;i<G[x].size();++i)
			{
				Edge &e=edges[G[x][i]];
				if(e.cap>e.flow && d[e.to]>d[x]+e.cost)
				{
					d[e.to]=d[x]+e.cost;
					p[e.to]=G[x][i];
					a[e.to]=min(a[x],e.cap-e.flow);
					if(!inq[e.to]) inq[e.to]=1,que.push(e.to);
				}
			}
		}
		if(d[t]==INF) return 0;
		flow+=a[t];
		cost+=d[t];    /// multiply by d[t]*a[t] if per unit cost is given.
		int u=t;
		while(u!=s)
		{
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return 1;
	}
	pll solve()
	{
		L flow=0,cost=0;
		while(spfa(flow,cost));
		return make_pair(cost,flow);
	}
}

int main()
{
    int nV;
    cin>>nV;
    nV+=2;
    string s;
    cin>>s;
    int q;
    cin>>q;
    string st[q+10];
    long long cs[q+10];
    for(int i=0;i<q;i++){
        cin>>st[i]>>cs[i];
    }
    mcmf::init(0,s.size()+1,nV);
    for(int i=0;i<q;i++){
        for(int j=0;j+st[i].size()<=s.size();j++){
            bool flg=true;
            for(int l=j,k=0;l<j+st[i].size();l++,k++){
                if(st[i][k]!=s[l]) flg=false;
            }
            if(flg){
                mcmf::addEdge(j+1,j+st[i].size()+1,1,-cs[i]);
                //cout<<j+1<<" "<<j+st[i].size()+1<<endl;
            }
        }
    }
    long long x;
    cin>>x;
    mcmf::addEdge(0,1,x,0);
    for(int i=0;i<s.size();i++){
        mcmf::addEdge(i+1,i+2,x,0);
       // cout<<i+1<<" "<<i+2<<endl;
    }
    pll ans=mcmf::solve();
    cout<<-ans.first<<endl;
}
