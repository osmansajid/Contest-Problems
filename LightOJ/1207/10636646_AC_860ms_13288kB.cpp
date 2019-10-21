#include<bits/stdc++.h>
using namespace std;
#define mx 200010
long long arr[mx];

//info is a structure to store the sums and update values(prop)
struct info{
    long long sum=0;
    long long prop=-1;
}tree[mx * 3];//3* of array size

//creates the tree
void init(int node,int b,int e){
    if(b==e){
        tree[node].sum=0;
        tree[node].prop=-1;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].prop=-1;
}

//when a node is visited update is used to update its children's prop values
void update(int node,int b,int e){
    //checking if leaf node or not
    if(b!=e){
        //if not leaf node then update its both children's prop value
        tree[2*node].prop=tree[node].prop;
        tree[(2*node)+1].prop=tree[node].prop;
    }
    //update its sum value as its not updated when we return from in range condition
    tree[node].sum=tree[node].prop*(e-b+1);
    //finally making its prop value -1 again meaning not visited and thus we need not to update its children anymore
    tree[node].prop=-1;
}
//updates all numbers in a given range from i to j...such as adding a value to all the numbers in the range
void update2(int node,int b,int e,int i,int j,long long newVal){
    //checking if previously visited or not...-1 means not visited
    if(tree[node].prop!=-1){
        update(node,b,e);
    }
    if(e<i || b>j){
        return ;
    }
    if(b>=i && e<=j){
        tree[node].sum= ((e-b+1)*newVal);
        if(b!=e){
            tree[2*node].prop=newVal;
            tree[(2*node)+1].prop=newVal;
        }
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update2(left,b,mid,i,j,newVal);
    update2(right,mid+1,e,i,j,newVal);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

//gives ans to the cum sum in a given range of i to j... carry passes the updated value
long long query(int node,int b,int e,int i,int j,long long carry=0){
    if(tree[node].prop!=-1){
        update(node,b,e);
    }
    if(e<i || b>j){
        return 0;
    }
    if(b>=i && e<=j){
        return (tree[node].sum);
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    long long res1=query(left,b,mid,i,j,tree[node].prop);
    long long res2=query(right,mid+1,e,i,j,tree[node].prop);
    return res1+res2;
}


int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,low=INT_MAX,high=0,frq[mx],cnt=0;
        memset(frq,0,sizeof frq);
        init(1,1,mx);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int l,r;
            scanf("%d %d",&l,&r);
            update2(1,1,mx,l,r,i);
            low=min(low,l);
            high=max(high,r);
        }
        for(int i=low;i<=high;i++){
            int x=query(1,1,mx,i,i,0);
            if(frq[x]==0){
                cnt++;
                frq[x]=1;
            }
        }
        printf("Case %d: %d\n",++tc,cnt);
    }
}


