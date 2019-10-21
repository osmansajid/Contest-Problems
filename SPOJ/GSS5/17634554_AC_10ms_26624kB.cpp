#include<bits/stdc++.h>
using namespace std;
#define mx 100010
long long arr[mx];

//info is a structure to store the sums and update values(prop)
struct info{
    long long sum,pre,suf,tot;
}tree[mx * 3];//3* of array size

info combine(info x,info y){
    info ret;
    ret.sum=max(max(x.sum,y.sum),x.suf+y.pre);
    ret.pre=max(x.pre,x.tot+y.pre);
    ret.suf=max(y.suf,y.tot+x.suf);
    ret.tot=x.tot+y.tot;
    return ret;
}

//creates the tree
void init(int node,int b,int e){
    if(b==e){
        tree[node].sum=arr[b];
        tree[node].pre=arr[b];
        tree[node].suf=arr[b];
        tree[node].tot=arr[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=combine(tree[left],tree[right]);
}

//gives ans to the cum sum in a given range of i to j... carry passes the updated value
info query(int node,int b,int e,int i,int j,long long carry=0){
    if(e<i || b>j){
        info ret;
        ret.sum=ret.pre=ret.suf=-INT_MAX;
        ret.tot=0;
        return ret;
    }
    if(b>=i && e<=j){
        return tree[node];
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    return combine(query(left,b,mid,i,j,carry),query(right,mid+1,e,i,j,carry));
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        long long ss[n+1];
        memset(ss,0,sizeof ss);
        for(int i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
            ss[i]=ss[i-1]+arr[i];
        }
        init(1,1,n);
        int q;
        scanf("%d",&q);
        while(q--){
            int left1,right1,left2,right2;
            scanf("%d %d %d %d",&left1,&right1,&left2,&right2);
            if(left2>right1){
                printf("%lld\n",query(1,1,n,left1,right1).suf+ss[left2-1]-ss[right1]+query(1,1,n,left2,right2).pre);
            }
            else if(left2==right1){
                printf("%lld\n",query(1,1,n,left1,right1).suf+query(1,1,n,left2,right2).pre-arr[left2]);
            }
            else{
                printf("%lld\n",max(query(1,1,n,left2,right1).sum,max(query(1,1,n,left1,right1).suf+query(1,1,n,right1,right2).pre-arr[right1],query(1,1,n,left1,left2).suf+query(1,1,n,left2,right2).pre-arr[left2])));
            }
        }
    }
}
