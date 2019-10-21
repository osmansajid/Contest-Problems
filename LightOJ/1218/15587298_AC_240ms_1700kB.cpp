#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define M 101
#define INF INT_MAX
int m,n;
int pairU [M+1];
int pairV [M+1];
int setA [M+1];
int setB [M+1];
int dist [M+1];
vector<int>adj[M];

bool bfs(){
    queue<int> Q;
    for (int i=1; i<=m; i++){
        if (pairU[i]==NIL){
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        if (dist[u] < dist[NIL]){
            for (int i=0; i<adj[u].size(); ++i){
                int v = adj[u][i];
                if (dist[pairV[v]] == INF){
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

bool dfs(int u){
    if (u != NIL){
        for (int i=0; i<adj[u].size(); ++i){
            int v = adj[u][i];
            if (dist[pairV[v]] == dist[u]+1){
                if (dfs(pairV[v]) == true){
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroftKarp(){
    for (int i=1; i<=m; i++) pairU[i] = NIL;
    for (int i=1; i<=n; i++) pairV[i] = NIL;
    int result = 0;
    while (bfs()){
        for (int i=1; i<=m; i++){
            if (pairU[i]==NIL && dfs(i))result++;
        }
    }
    return result;
}

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        for(int i=0;i<M;i++)adj[i].clear();
        cin>>n;
        int j=0;
        vector<int>a;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(mp[x]==0){
                a.push_back(x);
                mp[x]=1;
            }
        }
        sort(a.begin(),a.end());
        int len=a.size(),siz=a.size(),sz=0,now=0;
        m=n=a.size();
        //map<int,int>mul;
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                if(a[j]%a[i]==0){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        len-=hopcroftKarp();
        //cout<<len<<endl;
        vector<int>res;
        while(now<siz){
            vector<int>tmpadj[M];
            for(int i=0;i<M;i++)tmpadj[i]=adj[i];
            for(int i=0;i<M;i++)adj[i].clear();
            vector<int>temp1;
            temp1.push_back(a[now]);
            for(int i=0;i<siz;i++){
                if(a[i]%a[now]!=0){
                   temp1.push_back(a[i]);
                }
            }
            sort(temp1.begin(),temp1.end());
            for(int i=0;i<temp1.size();i++){
                for(int j=i+1;j<temp1.size();j++){
                    if(temp1[j]%temp1[i]==0){
                        adj[i+1].push_back(j+1);
                    }
                }
            }
            int xx=temp1.size()-hopcroftKarp();
            //cout<<xx<<" "<<len<<endl;
            if(xx==len){
                res.push_back(a[now]);
                siz=temp1.size();
                a=temp1;
                now++;
            }
            else{
                for(int i=0;i<M;i++)adj[i]=tmpadj[i];
                now++;
            }
        }
        cout<<"Case "<<++tc<<": ";
        for(int i=0;i<res.size()-1;i++) cout<<res[i]<<" ";
        cout<<res[res.size()-1]<<endl;
    }
}
