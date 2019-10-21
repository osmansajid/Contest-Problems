#include<bits/stdc++.h>
using namespace std;
const int MAX=10100;
int que[MAX];
template <class T>
struct Edge {
   int to, next;
   T cap, flow;
   Edge(int to, int next, T cap) {
      this->to = to;
      this->next = next;
      this->cap = cap;
      this->flow = 0;
   }
};
template <class T>
struct Dinic {
   T INF;
   const int nodes;
   int source, sink, lvl[MAX], nodeEnd[MAX], last[MAX];
   vector < Edge <T> > edgeList;

   Dinic(int n) : nodes(n), INF(numeric_limits<T>::max() / 4) { fill(nodeEnd, nodeEnd+n, -1); }
   void addEdge(int u, int v, T cap = 1) {
      edgeList.push_back(Edge<T> (v, nodeEnd[u], cap));
      nodeEnd[u] = (int)edgeList.size()-1;
      edgeList.push_back(Edge<T> (u, nodeEnd[v], 0));
      nodeEnd[v] = (int)edgeList.size()-1;
   }

   // bfs
   bool createLevel() {
      memset(lvl, -1, nodes * sizeof(int));
      int qs = 0, qt = 0;
      que[qs] = source, lvl[source] = 0;

      while(qs <= qt) {
         int nd = que[qs++], ch;
         for(int i = nodeEnd[nd]; i != -1; i = edgeList[i].next)
            if(lvl[ch = edgeList[i].to] == -1 && edgeList[i].cap > edgeList[i].flow)
               lvl[ch] = lvl[nd] + 1, que[++qt] = ch;
      }

      return lvl[sink] != -1;
   }

   // dfs
   T blockingFlow(int nd, T flow) {
      if(nd == sink) return flow;
      int ch;
      T pflow = flow;

      for(int &i = last[nd]; i != -1; i = edgeList[i].next) if(lvl[ch = edgeList[i].to] == lvl[nd]+1) {
         T pushed = blockingFlow(ch, min(pflow, edgeList[i].cap - edgeList[i].flow));
         pflow -= pushed;
         edgeList[i].flow += pushed;
         edgeList[i ^ 1].flow -= pushed;
         if(!pflow) break;
      }

      return flow - pflow;
   }

   T maxFlow(int src, int snk) {
      //REP(i, edgeList.size()) edgeList[i].flow = 0;
      source = src, sink = snk;
      T tot = 0;

      while(createLevel()) {
         memcpy(last, nodeEnd, nodes * sizeof(int));
         tot += blockingFlow(source, INF);
      }

      return tot;
   }
};

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int cost[n+10];
        for(int i=0;i<n-2;i++){
            cin>>cost[i];
        }
        int ss=1,tt=(n-1)*2;
        Dinic<long long> xx( (n-1)*2 +1 );
        int id[n*2];
        for(int i=2,j=0;i<(n-1)*2;i+=2,j++){
            xx.addEdge(i,i+1,cost[j]);
            xx.addEdge(i+1,i,cost[j]);
            id[j+2]=i;
            //cout<<j+2<<" "<<i<<endl;
        }
        id[1]=1;
        id[n]=(n-1)*2;
        for(int i=0;i<m;i++){
            int u,v,co,uu,vv;
            cin>>u>>v>>co;
            if(u==ss ) uu=id[u];
            else if(u==n) uu=id[n];
            else uu=id[u]+1;
            vv=id[v];
            //cout<<u<<" "<<v<<" "<<co<<endl;
            xx.addEdge(uu,vv,co);
            if(v==ss ) vv=id[v];
            else if(v==n) vv=id[n];
            else vv=id[v]+1;
            uu=id[u];
            xx.addEdge(vv,uu,co);
        }
        long long ans=xx.maxFlow(ss,tt);
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
}
