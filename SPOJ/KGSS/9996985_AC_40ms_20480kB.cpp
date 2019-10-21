#include<bits/stdc++.h>
using namespace std;

#define mx 100010
int arr[mx];

//info is a structure to store the sums and update values(prop)
struct info{
    long long max1=0;
    long long max2=0;
}tree[mx * 3];//3* of array size

//creates the tree
void init(int node,int b,int e){
    if(b==e){
        tree[node].max1=arr[b];
        tree[node].max2=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].max1=max(max(tree[left].max1,tree[right].max1),max(tree[left].max2,tree[right].max2));
    if(tree[node].max1==tree[left].max1) tree[node].max2=max(max(tree[left].max2,tree[right].max1),tree[right].max2);
    else if(tree[node].max1==tree[left].max2) tree[node].max2=max(max(tree[left].max1,tree[right].max1),tree[right].max2);
    else if(tree[node].max1==tree[right].max1) tree[node].max2=max(max(tree[left].max2,tree[left].max1),tree[right].max2);
    else tree[node].max2=max(max(tree[left].max2,tree[left].max1),tree[right].max1);
}

//gives ans to the cum sum in a given range of i to j... carry passes the updated value

info merg(info tr,info tr2){
    info tr3;
    tr3.max1=max(max(tr.max1,tr2.max1),max(tr.max2,tr2.max2));
    if(tr3.max1==tr.max1) tr3.max2=max(max(tr.max2,tr2.max1),tr2.max2);
    else if(tr3.max1==tr.max2) tr3.max2=max(max(tr.max1,tr2.max1),tr2.max2);
    else if(tr3.max1==tr2.max1) tr3.max2=max(max(tr.max2,tr.max1),tr2.max2);
    else tr3.max2=max(max(tr.max2,tr.max1),tr2.max1);
    return tr3;
}
info query(int node,int b,int e,int i,int j,int carry=0){
    if(e<i || b>j){
        info tr;
        tr.max1=0;
        tr.max2=0;
        return tr;
    }
    if(b>=i && e<=j){
        return tree[node];
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    info res1=query(left,b,mid,i,j,carry);
    info res2=query(right,mid+1,e,i,j,carry);
    return merg(res1,res2);
}

void update(int node, int b, int e, int i, long long newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node].max1 = newvalue;
        tree[node].max2= 0;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, newvalue);
    update(right, mid + 1, e, i, newvalue);
    tree[node].max1=max(max(tree[left].max1,tree[right].max1),max(tree[left].max2,tree[right].max2));
    if(tree[node].max1==tree[left].max1) tree[node].max2=max(max(tree[left].max2,tree[right].max1),tree[right].max2);
    else if(tree[node].max1==tree[left].max2) tree[node].max2=max(max(tree[left].max1,tree[right].max1),tree[right].max2);
    else if(tree[node].max1==tree[right].max1) tree[node].max2=max(max(tree[left].max2,tree[left].max1),tree[right].max2);
    else tree[node].max2=max(max(tree[left].max2,tree[left].max1),tree[right].max1);
}

int main()
{
        int n,q;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        scanf("%d",&q);
        init(1,1,n);
        for(int i=1;i<=q;i++){
            getchar();
            char ch;
            scanf("%c",&ch);
            //printf("%d",ch);
            //getchar();
            if(ch=='Q'){
                int b,e;
                scanf("%d %d",&b,&e);
                info tr=query(1,1,n,b,e,0);
                printf("%lld\n",tr.max1+tr.max2);
            }
            else{
                int b,x;
                scanf("%d %d",&b,&x);
                update(1,1,n,b,x);
            }
        }
}
