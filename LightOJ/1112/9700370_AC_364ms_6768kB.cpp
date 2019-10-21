#include<bits/stdc++.h>
using namespace std;
#define mx 100010
int arr[mx];

//info is a structure to store the sums and update values(prop)
struct info{
    long long sum;
    long long prop;
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
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].prop=0;
}

//gives ans to the cum sum in a given range of i to j... carry passes the updated value
long long query(int node,int b,int e,int i,int j,int carry=0){
    if(e<i || b>j){
        return 0;
    }
    if(b>=i && e<=j){
        return (tree[node].sum+ carry*(e-b+1));
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int res1=query(left,b,mid,i,j,carry+tree[node].prop);
    int res2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return res1+res2;
}

//updates a number of an index
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node].sum = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

//updates all numbers in a given range from i to j...such as adding a value to all the numbers in the range
void update2(int node,int b,int e,int i,int j,int newVal){
    if(e<i || b>j){
        return ;
    }
    if(b>=i && e<=j){
        tree[node].sum+= ((e-b+1)*newVal);
        tree[node].prop+=newVal;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update2(left,b,mid,i,j,newVal);
    update2(right,mid+1,e,i,j,newVal);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
int main()
{
    int n,q,t,tc=0;
    scanf("%d",&t);
    while(t--){
       printf("Case %d:\n",++tc);
       scanf("%d %d",&n,&q);
       for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
       init(1,1,n);
       for(int i=0;i<q;i++){
            int ch;
            scanf("%d",&ch);
            if(ch==1){
                int x;
                scanf("%d",&x);
                printf("%lld\n",query(1,1,n,x+1,x+1,0));
                update(1,1,n,x+1,0);
            }
            else if(ch==2){
                int x,v;
                scanf("%d %d",&x,&v);
                update2(1,1,n,x+1,x+1,v);
            }
            else{
                int b,e;
                scanf("%d %d",&b,&e);
                printf("%lld\n",query(1,1,n,b+1,e+1,0));
            }
       }
    }
}
