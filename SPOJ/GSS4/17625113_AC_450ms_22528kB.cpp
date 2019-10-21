#include<bits/stdc++.h>
using namespace std;
#define mx 100010
long long arr[mx];

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
    int n,tc=0;
    int freq[mx];
    while(scanf("%d",&n)!=EOF){
        memset(freq,0,sizeof freq);
        for(int i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
        }
        init(1,1,n);
        int next[n+2],prev[n+2];
        for(int i=0;i<=n;i++){
            next[i]=i+1;
        }
        //next[n]=mx-1;
        for(int i=1;i<=n+1;i++){
            prev[i]=i-1;
        }
        //prev[1]=0;
        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",++tc);
        while(q--){
            int ch,left,right;
            scanf("%d %d %d",&ch,&left,&right);
            if(left>right) swap(left,right);
            if(ch==1){
                printf("%lld\n",query(1,1,n,left,right));
            }
            else{
                int cur=left;
                while(cur<=right){
                    long long val=sqrt(arr[cur]);
                    arr[cur]=val;
                    update(1,1,n,cur,val);
                    if(val==1 && freq[cur]==0){
                        freq[cur]=1;
                        next[prev[cur]]=next[cur];
                        prev[next[cur]]=prev[cur];
                    }
                    //cout<<cur<<" "<<next[cur]<<" "<<prev[cur]<<" "<<next[prev[next[cur]]]<<endl;;
                    cur=next[prev[next[cur]]];
                }
                //cout<<endl;
            }
        }
    }
}
