#include<bits/stdc++.h>
using namespace std;
#define mx 100010
int arr[mx];

//info is a structure to store the sums and update values(prop)
struct info{
    long long sum;
    long long prop;
}tree[mx * 3];//3* of array size


struct que{
    int l,r,in;
};

bool operator < (que a,que b){
    return a.r<b.r;
}

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
long long query(int node,int b,int e,int i,int j,long long carry=0){
    if(e<i || b>j){
        return 0;
    }
    if(b>=i && e<=j){
        return (tree[node].sum+ carry*(e-b+1));
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    long long res1=query(left,b,mid,i,j,carry+tree[node].prop);
    long long res2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return res1+res2;
}

//updates a number of an index
void update(int node, int b, int e, int i, long long newvalue)
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


int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        int a[n+10];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        init(1,1,n);
        que qq[q];
        for(int i=0;i<q;i++){
            int left,right;
            scanf("%d %d",&left,&right);
            qq[i].l=left;
            qq[i].r=right;
            qq[i].in=i;
        }
        sort(qq,qq+q);
        int last[mx],x=0;
        long long ans[q];
        memset(last,0,sizeof last);
        for(int i=1;i<=n;i++){
            if(last[a[i]]){
                update(1,1,n,last[a[i]],0);
                last[a[i]]=i;
                update(1,1,n,last[a[i]],1);
            }
            else{
                last[a[i]]=i;
                update(1,1,n,last[a[i]],1);
            }
            while(i==qq[x].r){
                ans[qq[x].in]=query(1,1,n,qq[x].l,qq[x].r);
                x++;
            }
        }
        printf("Case %d:\n",++tc);
        for(int i=0;i<q;i++)printf("%lld\n",ans[i]);
    }
}
