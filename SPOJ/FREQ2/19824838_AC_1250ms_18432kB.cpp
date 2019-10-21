#include<bits/stdc++.h>
using namespace std;
int n,q,blk,a[100010],frq[100010],tot[100010],mx=-1;

struct query{
    int l,r,id;
}qq[100010];

bool cmp(query x,query y){
    int blkx,blky;
    blkx=x.l/blk;
    blky=y.l/blk;
    if(blkx!=blky) return blkx<blky;
    return x.r<y.r;
}

void add(int pos){
    frq[a[pos]]++;
    tot[frq[a[pos]]]++;
    tot[frq[a[pos]]-1]--;
    if(frq[a[pos]]>mx){
        mx=frq[a[pos]];
    }
}

void rmv(int pos){
    frq[a[pos]]--;
    tot[frq[a[pos]]]++;
    tot[frq[a[pos]]+1]--;
    if(tot[mx]==0){
        mx=frq[a[pos]];
    }
}

int main()
{
    scanf("%d %d",&n,&q);
    blk=sqrt(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<q;i++){
        scanf("%d %d",&qq[i].l,&qq[i].r);
        qq[i].id=i;
    }
    sort(qq,qq+q,cmp);

    int curl=0,curr=-1,ans[q];
    for(int i=0;i<q;i++){
        while(curl<qq[i].l) rmv(curl++);
        while(curl>qq[i].l) add(--curl);
        while(curr<qq[i].r) add(++curr);
        while(curr>qq[i].r) rmv(curr--);
        ans[qq[i].id]=mx;
    }

    for(int i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }
}
