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
void init1(int node,int b,int e){
    if(b==e){
        //storing index not the value in segment tree
        tree[node].sum=arr[b];
        tree[node].prop=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init1(left,b,mid);
    init1(right,mid+1,e);
    //minval function will return index of minimum valued number in arr
    tree[node].sum=min(tree[left].sum,tree[right].sum);
    tree[node].prop=0;
}

//return minimum valued number's index in a given range
long long query1(int node,int b,int e,int i,int j,int carry=0){
    if(e<i || b>j){
        //if out of bound return -1
        return INT_MAX;
    }
    if(b>=i && e<=j){
        return tree[node].sum;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int res1=query1(left,b,mid,i,j,carry);
    int res2=query1(right,mid+1,e,i,j,carry);
    //minval function will return index of minimum valued number in arr
    return min(res1,res2);
}

struct info2{
    long long sum=INT_MIN;
    long long prop=0;
}tree2[mx * 3];//3* of array size

//creates the tree
void init2(int node,int b,int e){
    if(b==e){
        //storing index not the value in segment tree
        tree2[node].sum=arr[b];
        tree2[node].prop=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init2(left,b,mid);
    init2(right,mid+1,e);
    //minval function will return index of minimum valued number in arr
    tree2[node].sum=max(tree2[left].sum,tree2[right].sum);
    tree2[node].prop=0;
}

long long query2(int node,int b,int e,int i,int j,int carry=0){
    if(e<i || b>j){
        //if out of bound return -1
        return INT_MIN;
    }
    if(b>=i && e<=j){
        return tree2[node].sum;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int res1=query2(left,b,mid,i,j,carry);
    int res2=query2(right,mid+1,e,i,j,carry);
    //minval function will return index of minimum valued number in arr
    return max(res1,res2);
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,d;
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        init1(1,1,n);
        init2(1,1,n);
        long long mmax=0;
        for(int i=1;i<=n-d+1;i++){
            long long mini=query1(1,1,n,i,i+d-1,0);
            long long maxi=query2(1,1,n,i,i+d-1,0);
            if(maxi-mini>mmax){
                mmax=maxi-mini;
            }
        }
        printf("Case %d: %lld\n",++tc,mmax);
    }
}