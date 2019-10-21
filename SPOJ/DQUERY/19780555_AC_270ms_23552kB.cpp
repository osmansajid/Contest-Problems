#include<bits/stdc++.h>
using namespace std;
int n,blk,a[30010],frq[1000010],cnt;
struct query{
    int l,r,id;
}qq[200010];

bool cmp (query x,query y){
    int blkx,blky;
    blkx=x.l/blk;
    blky=y.l/blk;
    if(blkx!=blky)return blkx<blky;
    return x.r<y.r;
}

void add(int pos){
    frq[a[pos]]++;
    if(frq[a[pos]]==1) cnt++;
    return;
}

void rmv(int pos){
    frq[a[pos]]--;
    if(frq[a[pos]]==0) cnt--;
    return;
}

int main()
{
    memset(frq,0,sizeof frq);
    cnt=0;
    scanf("%d",&n);
    blk=sqrt(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int q;
    scanf("%d",&q);

    for(int i=0;i<q;i++){
        scanf("%d %d",&qq[i].l,&qq[i].r);
        qq[i].id=i;
    }

    sort(qq,qq+q,cmp);

    int curl=0,curr=-1;
    int ans[q];
    for(int i=0;i<q;i++){
        while(curl>qq[i].l)add(--curl);
        while(curl<qq[i].l)rmv(curl++);
        while(curr>qq[i].r)rmv(curr--);
        while(curr<qq[i].r)add(++curr);
        ans[qq[i].id]=cnt;
    }

    for(int i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }
}
