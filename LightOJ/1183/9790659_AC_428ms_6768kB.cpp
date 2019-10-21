#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

#define    ll               long long int
#define    vi 	            vector < int >
#define    vii              vector < vector < int > >
#define    pii              pair< int, int >
#define    ff               first
#define    ss               second
#define    clr(a)           memset(a,0,sizeof(a))
#define    clr_(a)          memset(a,-1,sizeof(a))
#define    eps              1e-9
#define    sqr(a)           a*a
#define    inf              INT_MAX
#define    pi               acos(-1.0)
#define    INF              1e18
#define    READ(f)          freopen(f, "r", stdin)
#define    WRITE(f)         freopen(f, "w", stdout)
#define    rep1(i,n)        for(int i=1;i<=n;i++)
#define    rep0(i,n)        for(int i=0;i<n;i++)
#define    FOR(i,L,R) 	    for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	    for (int i = L; i >= R; i--)

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

//ios_base::sync_with_stdio(0);  cin.tie(0);


//*******************template ends*****************

#define mx 100010
int arr[mx];

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
        int n,q;
        scanf("%d %d",&n,&q);
        printf("Case %d:\n",++tc);
        init(1,1,n);
        rep1(i,q){
            int ch;
            scanf("%d",&ch);
            if(ch==1){
                int b,e,x;
                scanf("%d %d %d",&b,&e,&x);
                update2(1,1,n,b+1,e+1,x);
            }
            else{
                int b,e;
                scanf("%d %d",&b,&e);
                ll num=query(1,1,n,b+1,e+1,0);
                ll den=e-b+1;
                ll x=gcd(num,den);
                den/=x;
                num/=x;
                if(den==1) printf("%lld\n",num);
                else if(num==0) printf("0\n");
                else printf("%lld/%lld\n",num,den);
            }
        }
    }
}
