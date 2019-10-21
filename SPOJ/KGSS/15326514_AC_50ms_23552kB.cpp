#include<bits/stdc++.h>
using namespace std;
#define mx 100010
int arr[mx];

struct info{
    long long sum1;
    long long sum2;
    long long prop;
}tree[mx * 3];//3* of array size

void init(int node,int b,int e){
    if(b==e){
        tree[node].sum1=arr[b];
        tree[node].sum2=0;
        tree[node].prop=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum1=max(tree[left].sum1,tree[right].sum1);
    if(tree[left].sum1>tree[right].sum1) tree[node].sum2=max(tree[left].sum2,tree[right].sum1);
    else tree[node].sum2=max(tree[left].sum1,tree[right].sum2);
    tree[node].prop=0;
}

pair<long long,long long> query(int node,int b,int e,int i,int j,long long carry=0){
    if(e<i || b>j){
        return make_pair(0,0);
    }
    if(b>=i && e<=j){
        return make_pair(tree[node].sum1,tree[node].sum2);
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    pair<long long,long long> res1=query(left,b,mid,i,j,carry+tree[node].prop);
    pair<long long,long long> res2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    //cout<<b<<" "<<e<<" "<<res1.first<<" "<<res1.second<<" "<<res2.first<<" "<<res2.second<<endl;
    return make_pair(max(res1.first,res2.first),(res1.first>res2.first)?max(res1.second,res2.first):max(res1.first,res2.second));
}

void update(int node, int b, int e, int i, long long newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node].sum1 = newvalue;
        tree[node].sum2 = 0;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node].sum1=max(tree[Left].sum1,tree[Right].sum1);
    if(tree[Left].sum1>tree[Right].sum1) tree[node].sum2=max(tree[Left].sum2,tree[Right].sum1);
    else tree[node].sum2=max(tree[Left].sum1,tree[Right].sum2);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
         scanf("%d",&arr[i]);
    }
    init(1,1,mx);
    int q;
    scanf("%d",&q);
    while(q--){
        getchar();
        char c;
        int s,v;
        scanf("%c %d %d",&c,&s,&v);
        //cout<<c<<s<<v<<endl;
        if(c=='U'){
            update(1,1,mx,s,v);
        }
        else{
            pair<long long,long long> pi=query(1,1,mx,s,v);
            //cout<<pi.first<<" "<<pi.second<<endl;
            printf("%lld\n",pi.first+pi.second);
        }
    }
}
