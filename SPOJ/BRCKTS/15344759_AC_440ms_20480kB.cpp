#include<bits/stdc++.h>
using namespace std;
#define mx 100010
int arr[mx];

//info is a structure to store the sums and update values(prop)
struct info{
    long long sum;
    long long ok;
}tree[mx * 3];//3* of array size

//creates the tree
void init(int node,int b,int e){
    if(b==e){
        tree[node].sum=arr[b];
        //tree[node].ltree=arr[b];
        tree[node].ok=arr[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].ok=min(tree[left].ok,tree[left].sum+tree[right].ok);
}


//updates a number of an index
void update(int node, int b, int e, int i)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        if(tree[node].sum==-1)tree[node].sum = 1;
        else tree[node].sum= -1;
        tree[node].ok=tree[node].sum;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i);
    update(Right, mid + 1, e, i);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
    tree[node].ok=min(tree[Left].ok,tree[Left].sum+tree[Right].ok);
}
int main()
{
    int t=10,tc=0;
    while(t--){
        printf("Test %d:\n",++tc);
        int n;
        memset(tree,0,sizeof tree);
        bool ok=false;
        scanf("%d",&n);
        char s[n+10];
        scanf("%s",s);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                arr[i+1]=1;
            }
            else {
                arr[i+1]=-1;
            }
        }
        init(1,1,n);
        int q;
        scanf("%d",&q);
        //printf("Test %d:\n",++tc);
        while(q--){
            int x;
            scanf("%d",&x);
            if(x){
                update(1,1,n,x);
            }
            else{
                if(tree[1].sum==0 && tree[1].ok==0) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
}
