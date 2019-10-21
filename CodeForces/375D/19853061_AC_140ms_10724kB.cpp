#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100010];
int n,q,blk,a[100010],frq[100010],org[100010],vis[100010],tt=0,tot[100010],mx=-1;

struct range{
    int l,r;
}rng[100010];

struct query{
    int l,r,k,id,d;

    inline query() {}

    inline query(int a, int b, int c,int e){
        id = e;
        l = a, r = b, k=c, d = l / blk;
    }

    inline bool operator < (const query& other) const{
        if (d != other.d) return (d < other.d);
        return ((d & 1) ? (r > other.r) : (r < other.r));
    }
}qq[100010];


void add(int pos){
    frq[org[pos]]++;
    tot[frq[org[pos]]]++;
}

void rmv(int pos){
    frq[org[pos]]--;
    tot[frq[org[pos]]+1]--;
}

void dfs(int s){
    vis[s]=1;
    rng[s].l=tt;
    org[tt]=a[s];
    tt++;
    for(int i=0;i<adj[s].size();i++){
        int v=adj[s][i];
        if(!vis[v]){
            dfs(v);
        }
    }
    rng[s].r=tt-1;
}
int main()
{
    scanf("%d %d",&n,&q);
    blk=sqrt(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
//    for(int i=0;i<n;i++) cout<<org[i]<<" ";
//    cout<<endl;
    for(int i=0;i<q;i++){
        int x,k;
        scanf("%d %d",&x,&k);
        qq[i]=query(rng[x].l,rng[x].r,k,i);
        //cout<<qq[i].l<<" "<<qq[i].r<<endl;
    }
    sort(qq,qq+q);

    int curl=0,curr=-1,ans[q];
    for(int i=0;i<q;i++){
        while(curl<qq[i].l) rmv(curl++);
        while(curl>qq[i].l) add(--curl);
        while(curr<qq[i].r) add(++curr);
        while(curr>qq[i].r) rmv(curr--);
        ans[qq[i].id]=tot[qq[i].k];
        //cout<<qq[i].l<<" "<<qq[i].r<<" "<<tot[qq[i].k]<<" "<<qq[i].k<<endl;
    }

    for(int i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }
}
