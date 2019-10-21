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
    scanf("%d",&t);
    while(t--){
        int cap,n;
        scanf("%d%d",&cap,&n);
        Dinic <int> a(n+9);
        map<string,int>mp;
        mp["XXL"]=2;
        mp["XL"]=3;
        mp["L"]=4;
        mp["M"]=5;
        mp["S"]=6;
        mp["XS"]=7;
        int s,d;
        s=1;
        d=n+8;
        for(int i=2;i<=7;i++){
           a.addEdge(s,i,cap);
        }
        for(int i=1;i<=n;i++){
            string u,v;
            cin>>u>>v;
            a.addEdge(mp[u],i+7,1);
            a.addEdge(mp[v],i+7,1);
        }
        for(int i=1;i<=n;i++){
           a.addEdge(i+7,d,1);
        }


        if(a.maxFlow(s,d)==n)cout<<"Case "<<++tc<<": YES"<<endl;
        else cout<<"Case "<<++tc<<": NO"<<endl;
    }
}
