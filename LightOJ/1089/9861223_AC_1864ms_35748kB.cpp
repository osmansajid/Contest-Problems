#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

#define    ll               long long int
#define    vi               vector < int >
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
#define    FOR(i,L,R)       for (int i = L; i <= R; i++)
#define    ROF(i,L,R)       for (int i = L; i >= R; i--)

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

//ios_base::sync_with_stdio(0);  cin.tie(0);


//*******************template ends*****************
#define mx 100000010

map<int,int>tree;

//info is a structure to store the sums and update values(prop)
int sum(int indx)
{
    int Sum = 0;
    while (indx){
        Sum += tree[indx];
        indx -= indx & -indx;
    }
    return Sum;
}
//updates->
void update(int indx,int n, int val)
{
    while (indx <= n){
        tree[indx] += val;
        indx += indx & (-indx);
    }
}
int main()
{
    int t,tc=0;
    sc(t);
    while(t--){
        printf("Case %d:\n",++tc);
        int n,q;
        sc2(n,q);
        rep1(i,n){
            int b,e;
            sc2(b,e);
            update(b+1,mx,1);
            update(e+2,mx,-1);
        }
        rep1(i,q){
            int a;
            sc(a);
            printf("%d\n",sum(a+1));
        }
        tree.clear();
    }
}
