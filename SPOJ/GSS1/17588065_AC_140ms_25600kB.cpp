#include<bits/stdc++.h>
using namespace std;
#define mx 100010
int arr[mx];

//info is a structure to store the sums and update values(prop)
struct info{
    long long sum;
    long long pre;
    long long suff;
    long long tot;
}tree[mx * 3];//3* of array size

info combine(info x,info y){
    info ret;
    ret.sum=max(max(x.sum,y.sum),x.suff+y.pre);
    ret.pre=max(x.pre,x.tot+y.pre);
    ret.suff=max(y.suff,y.tot+x.suff);
    ret.tot=x.tot+y.tot;
    return ret;
}
//creates the tree
void init(int node,int b,int e){
    if(b==e){
        tree[node].sum=arr[b];
        tree[node].pre=arr[b];
        tree[node].suff=arr[b];
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
        ret.sum=ret.pre=ret.suff=ret.tot=-INT_MAX;
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
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
    }
    init(1,1,n);
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r ;
        scanf("%d%d",&l,&r);
        printf("%lld\n",query(1,1,n,l,r).sum);
    }
}
