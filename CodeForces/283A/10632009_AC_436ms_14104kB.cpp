#include<bits/stdc++.h>
using namespace std;
#define mx 200010
long long arr[mx];

//info is a structure to store the sums and update values(prop)
struct info{
    long long sum;
    long long prop;
}tree[mx * 4];//3* of array size

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

//updates all numbers in a given range from i to j by adding a value to all the numbers in the range
void update2(int node,int b,int e,int i,int j,long long newVal){
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
    long long n,i=1;
    scanf("%I64d",&n);
    init(1,1,mx);
    while(n--){
        int ch;
        scanf("%d",&ch);
        if(ch==1){
            long long b,e;
            scanf("%I64d %I64d",&b,&e);
            b=min(i,b);
            update2(1,1,mx,1,b,e);
        }
        else if(ch==2){
            long long x;
            i++;
            scanf("%I64d",&x);
            //update(1,1,mx,i,0);
            update2(1,1,mx,i,i,x);
        }
        else{
            //update(1,1,mx,i,0);
            update2(1,1,mx,i,i,-query(1,1,mx,i,i,0));
            i--;
        }

        double ans=(double)(query(1,1,mx,1,i,0))/(double)i;
        printf("%.8lf\n",ans);
    }
}


