#include<bits/stdc++.h>
using namespace std;
int n,q,blk;
int a[1000010],org[1000010],frq[1000010];
int cnt=0;
struct query{
    int l,r,id;
}qq[1000010];

bool cmp(query x,query y){
    int blkx,blky;
    blkx=x.l/blk;
    blky=y.l/blk;
    if(blkx!=blky) return blkx<blky;
    return x.r<y.r;
}

void add(int pos){
    frq[a[pos]]++;
    //cout<<a[pos]<<" "<<frq[a[pos]]<<" "<<tot<<endl;
    if(frq[a[pos]]==org[pos]) cnt++;
    else if(frq[a[pos]]==org[pos]+1) cnt--;
}

void rmv(int pos){
    frq[a[pos]]--;
    if(frq[a[pos]]==org[pos]) cnt++;
    else if(frq[a[pos]]==org[pos]-1) cnt--;
}

int main()
{
    scanf("%d %d",&n,&q);
    blk=sqrt(n);
    map<int,int>mp;
    int cur=1;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        org[i]=a[i];
        //cout<<a[i]<<endl;
    }

    for(int i=0;i<n;i++){
        //scanf("%d",&a[i]);
        if(mp[a[i]]!=0){
            a[i]=mp[a[i]];
        }
        else{
            mp[a[i]]=cur;
            a[i]=cur;
            cur++;
        }
        //cout<<a[i]<<endl;
    }

    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        qq[i].l=l-1;
        qq[i].r=r-1;
        qq[i].id=i;
    }

    sort(qq,qq+q,cmp);

    int curl=0,curr=-1;
    int ans[q];
    for(int i=0;i<q;i++){
        while(curl<qq[i].l) rmv(curl++);
        while(curl>qq[i].l) add(--curl);
        while(curr<qq[i].r) add(++curr);
        while(curr>qq[i].r) rmv(curr--);
        ans[qq[i].id]=cnt;
        //cout<<qq[i].l<<" "<<qq[i].r<<" "<<tot<<endl;
    }

    for(int i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }
}

