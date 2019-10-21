#include<bits/stdc++.h>
using namespace std;

#define mx 100010
int arr[mx];

struct info{
    long long sum1=0;
    long long sum2=0;
    long long prop;
}tree[mx * 3];//3* of array size

void init(int node,int b,int e){
    if(b==e){
        tree[node].sum1=0;
        tree[node].sum2=1;
        tree[node].prop=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum1=tree[left].sum1+tree[right].sum1;
    tree[node].sum2=tree[left].sum2+tree[right].sum2;
    tree[node].prop=0;
}

long long query(int node,int b,int e,int i,int j,long long carry=0){
    if(tree[node].prop){
        for(int i=0;i<tree[node].prop%2;i++){
            int temp=tree[node].sum2;
            tree[node].sum2=tree[node].sum1;
            tree[node].sum1= temp;
        }
        if(b!=e){
            tree[2*node].prop+=tree[node].prop;
            tree[2*node + 1].prop+=tree[node].prop;
        }
        tree[node].prop=0;
    }
    if(e<i || b>j){
        return 0;
    }
    if(b>=i && e<=j){
        return tree[node].sum1;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    long long res1=query(left,b,mid,i,j,carry+tree[node].prop);
    long long res2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return res1+res2;
}

void update(int node,int b,int e,int i,int j,long long newVal){
    if(tree[node].prop){
        for(int i=0;i<tree[node].prop%2;i++){
            int temp=tree[node].sum2;
            tree[node].sum2=tree[node].sum1;
            tree[node].sum1= temp;
        }
        if(b!=e){
            tree[2*node].prop+=tree[node].prop;
            tree[2*node + 1].prop+=tree[node].prop;
        }
        tree[node].prop=0;
    }
    if(e<i || b>j){
        return ;
    }
    if(b>=i && e<=j){
        int temp=tree[node].sum2;
        tree[node].sum2=tree[node].sum1;
        tree[node].sum1= temp;
        if(b!=e){
            tree[2*node].prop+=newVal;
            tree[2*node + 1].prop+=newVal;
        }
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,newVal);
    update(right,mid+1,e,i,j,newVal);
    tree[node].sum1=tree[left].sum1+tree[right].sum1;
    tree[node].sum2=tree[left].sum2+tree[right].sum2;
}

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    init(1,1,mx);
    while(q--){
        int c,s,e;
        scanf("%d %d %d",&c,&s,&e);
        if(!c)update(1,1,mx,s,e,1);
        else printf("%lld\n",query(1,1,mx,s,e,0));
    }
}
