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
#define    sc(a)            scanf("%d",&a)
#define    sc2(a,b)         scanf("%d %d",&a,&b)
#define    sc3(a,b,c)       scanf("%d %d %d",&a,&b,&c)
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

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/


//*******************template ends*****************


#define mx 200010
int arr[mx];

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
    while(sc(n)){
        if(n==0) break;
        if(tc!=0) printf("\n");
        printf("Case %d:\n",++tc);
        for(int i=1;i<=n;i++){
            sc(arr[i]);
        }
        init(1,1,n);
        char s[10];
        getchar();
        while(scanf("%s",s)){
            if(s[0]=='E') break;
            if(s[0]=='S'){
                getchar();
                int b;
                long long e;
                scanf("%d %lld",&b,&e);
                update(1,1,n,b,e);
            }
            else{
                getchar();
                int b,e;
                sc2(b,e);
                printf("%lld\n",query(1,1,n,b,e,0));
            }
        }
    }
}
