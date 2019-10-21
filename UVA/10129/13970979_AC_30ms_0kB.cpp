#include<bits/stdc++.h>
using namespace std;
#define N 30
#define white 0
#define grey  1
#define black 2
vector<int>adj[N];
stack<int>sta;
int disc[N],low[N],vis[N],in[N],id[N],out[N],com;

void dfs(int u){
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}

bool isConnected(int node){
    memset(vis,0,sizeof vis);
    dfs(node);
    for(int i=0;i<26;i++){
        if((in[i]!=0 || out[i]!=0) && vis[i]==0)return false;
    }
    return true;
}

int isEuler(int node){
    if(isConnected(node)){
        int cnt1=0,cnt2=0;
        for(int i=0;i<26;i++){
            if(out[i]!=in[i]){
                if(out[i]-in[i]==1) cnt1++;
                else if(out[i]-in[i]>1) return 0;
                if(in[i]-out[i]==1)cnt2++;
                else if(in[i]-out[i]>1) return 0;
            }
        }
        if(cnt1==0 && cnt2==0) return 2;
        else if(cnt1==1 && cnt2==1)return 1;
        else return 0;
    }
    else{
        return 0;
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string st[n];
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        for(int i=0;i<26;i++){
            adj[i].clear();
        }
        for(int i=0;i<n;i++){
            cin>>st[i];
            adj[st[i][0]-'a'].push_back(st[i][st[i].size()-1]-'a');
            in[st[i][st[i].size()-1]-'a']++;
            out[st[i][0]-'a']++;
        }
        bool x=false;
        for(int i=0;i<26;i++){
            if(isEuler(i)){
                x=true;
                break;
            }
        }
        if(x){
            cout<<"Ordering is possible."<<endl;
        }
        else cout<<"The door cannot be opened."<<endl;
        while(!sta.empty())sta.pop();
    }
}

