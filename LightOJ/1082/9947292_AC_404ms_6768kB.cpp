#include<bits/stdc++.h>
using namespace std;

#define mx 100010
int arr[mx];

//info is a structure to store the sums and update values(prop)
struct info{
    long long sum=INT_MAX;
    long long prop=0;
}tree[mx * 3];//3* of array size

//creates the tree
void init(int node,int b,int e){
    if(b==e){
        tree[node].sum=arr[b];
        tree[node].prop=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=min(tree[left].sum,tree[right].sum);
    tree[node].prop=0;
}

//gives ans to the cum sum in a given range of i to j... carry passes the updated value
long long query(int node,int b,int e,int i,int j,int carry=0){
    if(e<i || b>j){
        return INT_MAX;
    }
    if(b>=i && e<=j){
        return tree[node].sum;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int res1=query(left,b,mid,i,j,carry);
    int res2=query(right,mid+1,e,i,j,carry);
    return min(res1,res2);
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,q;
        printf("Case %d:\n",++tc);
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        init(1,1,n);
        for(int i=1;i<=q;i++){
            int b,e;
            scanf("%d %d",&b,&e);
            printf("%lld\n",query(1,1,n,b,e,0));
        }
    }
}
