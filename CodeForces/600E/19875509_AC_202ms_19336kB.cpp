#include<bits/stdc++.h>
using namespace std;
vector<long long>adj[100010];
long long n,q,blk,a[100010],frq[100010],org[100010],vis[100010],tt=0,tot[100010],mx=-1,ok[100010];

struct range{
    long long l,r;
}rng[100010];

struct query{
    long long  l,r,id,d;

    inline query() {}

    inline query(long long a, long long b,long long e){
        id = e;
        l = a, r = b, d = l / blk;
    }

    inline bool operator < (const query& other) const{
        if (d != other.d) return (d < other.d);
        return ((d & 1) ? (r > other.r) : (r < other.r));
    }
}qq[100010];


void add(long long pos){
    frq[org[pos]]++;
    tot[frq[org[pos]]]++;
    tot[frq[org[pos]]-1]--;
    if(frq[org[pos]]>mx){
        mx=frq[org[pos]];
    }
    ok[frq[org[pos]]]+=org[pos];
}

void rmv(long long pos){
    frq[org[pos]]--;
    tot[frq[org[pos]]]++;
    tot[frq[org[pos]]+1]--;
    if(tot[mx]==0){
        mx=mx-1;
    }
    ok[frq[org[pos]]+1]-=org[pos];
}

void dfs(long long s){
    vis[s]=1;
    rng[s].l=tt;
    org[tt]=a[s];
    tt++;
    for(long long i=0;i<adj[s].size();i++){
        long long v=adj[s][i];
        if(!vis[v]){
            dfs(v);
        }
    }
    rng[s].r=tt-1;
}
int main()
{
    scanf("%I64d",&n);
    blk=sqrt(n);
    for(long long i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
    }
    for(long long i=0;i<n-1;i++){
        long long u,v;
        scanf("%I64d %I64d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(long long i=0;i<n;i++){
        qq[i]=query(rng[i+1].l,rng[i+1].r,i);
        //cout<<rng[i+1].l<<" "<<rng[i+1].r<<endl;
    }
    sort(qq,qq+n);
    long long curl=0,curr=-1,ans[n];
    for(long long i=0;i<n;i++){
        while(curl<qq[i].l) rmv(curl++);
        while(curl>qq[i].l) add(--curl);
        while(curr<qq[i].r) add(++curr);
        while(curr>qq[i].r) rmv(curr--);
        ans[qq[i].id]=ok[mx];
        //cout<<qq[i].l<<" "<<qq[i].r<<" "<<endl;
    }

    for(long long i=0;i<n;i++){
        printf("%I64d ",ans[i]);
    }

    printf("\n");
}

