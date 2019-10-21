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
    int n;
    cin>>n;
    string s;
    cin>>s;
    L cst[n],cnt[30],fr=0,cost[n];
    map<pair<L,L>,L>mp;
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<n;i++){
        cin>>cst[i];
    }
    for(int i=0;i<n;i++){
        cnt[s[i]-'a']++;
    }
    mcmf::init(0,26+(n/2)+1,26+(n/2)+2);
    for(int i=0;i<26;i++){
        mcmf::addEdge(0,i+1,cnt[i],0);
        //cout<<0<<" "<<i+1<<" "<<cnt[i]<<endl;
    }
    for(int i=27;i<=26+(n/2);i++){
        mcmf::addEdge(i,26+(n/2)+1,2,0);
        //cout<<i<<" "<<26+(n/2)+1<<endl;
    }
    for(int i=0;i<n/2;i++){
        if(s[i]==s[n-i-1]){
            mcmf::addEdge(s[i]-'a'+1,26+i+1,1,-max(cst[i],cst[n-i-1]));
//            cout<<"One"<<endl;
//            cout<<s[i]-'a'+1<<" "<<26+i+1<<" "<<max(cst[i],cst[n-i-1])<<endl;
            mp[make_pair(s[i]-'a'+1,26+i+1)]=1;
        }
        else{
            mcmf::addEdge(s[i]-'a'+1,26+i+1,1,-cst[i]);
            mcmf::addEdge(s[n-i-1]-'a'+1,26+i+1,1,-cst[n-i-1]);
//            cout<<"two"<<endl;
//            cout<<s[i]-'a'+1<<" "<<26+i+1<<" "<<cst[i]<<endl;
//            cout<<s[n-i-1]-'a'+1<<" "<<26+i+1<<" "<<cst[n-i-1]<<endl;
            mp[make_pair(s[i]-'a'+1,26+i+1)]=1;
            mp[make_pair(s[n-i-1]-'a'+1,26+i+1)]=1;
        }
    }
    for(int i=1;i<=26;i++){
        for(int j=27;j<=26+(n/2);j++){
            if(mp[make_pair(i,j)]==0){
                    mcmf::addEdge(i,j,1,0);
            }
        }
    }
    cout<<-mcmf::solve().first<<endl;
}
