#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int vis[1001];
long long ch[1001];
vector<long long > adj[1001];

long long ncr[1001][1001];
long long nCr(long long n,long long r)
{
    if(r==1){
        return n;
    }
    if(r==n || r==0){
        return 1;
    }
    if(ncr[n][r]==-1){
        ncr[n][r]=(nCr(n-1,r-1)%mod + nCr(n-1,r)%mod)%mod;
    }
    return ncr[n][r];
}


long long dfs(int s){
    vis[s]=1;
    long long ret=1;
    for(int i=0;i<adj[s].size();i++){
        long long v=adj[s][i];
        if(vis[v]==0){
            ret+=dfs(v);
        }
    }
    return ch[s]=ret;
}

long long call(long long s){
    long long tot=ch[s]-1,ret=1;
    vis[s]=1;
    for(int i=0;i<adj[s].size();i++){
        long long u=adj[s][i];
        if(vis[u]==0){
            long long chtot=ch[u];
            ret=((((ret%mod)*(nCr(tot,chtot)%mod))%mod)*(call(u)%mod))%mod;
            //cout<<"KK "<<ret<<endl;
            tot-=chtot;
        }
    }
    return ret;
}
int main()
{
    memset(ncr,-1,sizeof ncr);
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        long long n,ans=0;
        scanf("%lld",&n);
        long long in[1001];
        memset(in,0,sizeof in);
        for(int i=0;i<n-1;i++){
            long long a,b;
            scanf("%lld%lld",&a,&b);
            adj[a].push_back(b);
            in[b]++;
        }
        for(long long i=1;i<=n;i++){
            if(in[i]==0){
                ans=i;
                break;
            }
        }
        memset(vis,0,sizeof vis);
        memset(ch,0,sizeof ch);
        dfs(ans);
        memset(vis,0,sizeof vis);
        long long v=call(ans);
        printf("Case %d: %lld\n",++tc,v);
        for(int i=0;i<=n;i++) adj[i].clear();
    }
}
