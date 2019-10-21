#include<bits/stdc++.h>
using namespace std;
#define mx 100010
int a[mx];
int tree[mx*3];

void init(int node,int b,int e)
{
    if(b==e){
        tree[node]=a[b];
        return;
    }
    int left=2*node;
    int right=(2*node)+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}

int  query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i){
        return 999999999;
    }
    if(b>=i && e<=j){
        return tree[node];
    }
    int left=2*node;
    int right=(2*node)+1;
    int mid=(b+e)/2;
    int res1,res2;
    res1=query(left,b,mid,i,j);
    res2=query(right,mid+1,e,i,j);
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
            scanf("%d",&a[i]);
        }
        init(1,1,n);
        //for(int i=1;i<=9;i++) cout<<tree[i]<<endl;
        for(int i=0;i<q;i++){
            int b,e;
            scanf("%d %d",&b,&e);
            printf("%d\n",query(1,1,n,b,e));
        }
    }
}
