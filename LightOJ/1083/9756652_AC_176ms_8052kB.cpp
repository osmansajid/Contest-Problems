#include<bits/stdc++.h>
using namespace std;

#define mx 100010
int arr[mx];

//returns the index of the minimum value between two given index of arr
int minVal(int i,int j){
    if(i==-1) return j;
    if(j==-1) return i;
    return (arr[i]<arr[j])?i:j;
}
//info is a structure to store the sums and update values(prop)
struct info{
    long long sum=INT_MAX;
    long long prop=0;
}tree[mx * 3];//3* of array size

//creates the tree
void init(int node,int b,int e){
    if(b==e){
        //storing index not the value in segment tree
        tree[node].sum=b;
        tree[node].prop=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    //minval function will return index of minimum valued number in arr
    tree[node].sum=minVal(tree[left].sum,tree[right].sum);
    tree[node].prop=0;
}

//return minimum valued number's index in a given range
long long query(int node,int b,int e,int i,int j,int carry=0){
    if(e<i || b>j){
        //if out of bound return -1
        return -1;
    }
    if(b>=i && e<=j){
        return tree[node].sum;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int res1=query(left,b,mid,i,j,carry);
    int res2=query(right,mid+1,e,i,j,carry);
    //minval function will return index of minimum valued number in arr
    return minVal(res1,res2);
}

//return the maximum rectangular area in the given histogran
long long Hist(int n,int l,int r){
    if(l>r) return INT_MIN;
    if(l==r) return arr[r];

    //returning and storing minimum value's index in m

    long long m=query(1,1,n,l,r);

    /* Return maximum of following three possible cases
       a) Maximum area in Left of min value (not including the min)
       a) Maximum area in right of min value (not including the min)
       c) Maximum area including min */

    return max(max(Hist(n,l,m-1),Hist(n,m+1,r)),(long long)(r-l+1)*arr[m]);
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        init(1,1,n);
        printf("Case %d: %lld\n",++tc,Hist(n,1,n));
    }
}
