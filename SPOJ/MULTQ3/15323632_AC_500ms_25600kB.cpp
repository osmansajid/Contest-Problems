#include<bits/stdc++.h>
using namespace std;
#define mx 200001

struct node{
    int sum1=0,sum2=0,sum3=0,prop=0;
}tree[mx*3];

void init(int node,int b,int e){
    //cout<<node<<" "<<b<<" "<<e<<endl;
    if(b==e){
        tree[node].sum3=1;
        tree[node].sum2=0;
        tree[node].sum1=0;
        tree[node].prop=0;
        return;
    }
    int left=2*node;
    int right=(2*node)+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum3=tree[left].sum3+tree[right].sum3;
    tree[node].sum2=tree[left].sum2+tree[right].sum2;
    tree[node].sum1=tree[left].sum1+tree[right].sum1;
    tree[node].prop=0;
}

void update(int node,int b,int e,int i,int j,int val){
    if(tree[node].prop){
        for(int i = 0 ; i < tree[node].prop%3 ; i++){
            int temp=tree[node].sum3;
            tree[node].sum3=tree[node].sum2;
            tree[node].sum2=tree[node].sum1;
            tree[node].sum1=temp;
        }
        if(b!=e){
            tree[2*node].prop+=tree[node].prop;
            tree[2*node+1].prop+=tree[node].prop;
        }
        tree[node].prop=0;
    }
    if(i>e || j<b) return;
    if(i<=b && j>=e){
        int temp=tree[node].sum3;
        tree[node].sum3=tree[node].sum2;
        tree[node].sum2=tree[node].sum1;
        tree[node].sum1=temp;
        //tree[node].prop+=val;
        if(b!=e){
            tree[2*node].prop+=val;
            tree[2*node+1].prop+=val;
        }
        return;
    }
    int left=2*node;
    int right=(2*node)+1;
    int mid=(e+b)/2;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node].sum1=tree[left].sum1+tree[right].sum1;
    tree[node].sum2=tree[left].sum2+tree[right].sum2;
    tree[node].sum3=tree[left].sum3+tree[right].sum3;
}

int query(int node,int b,int e,int i,int j,int carry){
    if(tree[node].prop){
        for(int i = 0 ; i < tree[node].prop%3 ; i++){
            int temp=tree[node].sum3;
            tree[node].sum3=tree[node].sum2;
            tree[node].sum2=tree[node].sum1;
            tree[node].sum1=temp;
        }
        if(b!=e){
            tree[2*node].prop+=tree[node].prop;
            tree[2*node+1].prop+=tree[node].prop;
        }
        tree[node].prop=0;
    }
    if(i>e || j<b) return 0;
    if(i<=b && j>=e){
        return tree[node].sum3;
    }
    int left=2*node;
    int right=(2*node)+1;
    int mid=(e+b)/2;
    int res1=query(left,b,mid,i,j,carry+tree[node].prop);
    int res2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return res1+res2;
}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    init(1,1,mx);
    while(q--){
        int ch,a,b;
        scanf("%d %d %d",&ch,&a,&b);
        if(ch){
            printf("%d\n",query(1,1,mx,a+1,b+1,0));
        }
        else{
            update(1,1,mx,a+1,b+1,1);
        }
    }
}


