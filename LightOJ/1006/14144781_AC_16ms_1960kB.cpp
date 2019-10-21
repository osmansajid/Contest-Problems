#include<bits/stdc++.h>
using namespace std;
long long dp[10010];

long long a, b, c, d, e, f;
long long fn( long long n ) {
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return dp[n]=(fn(n-1) % 10000007+ fn(n-2)% 10000007 + fn(n-3)% 10000007 + fn(n-4)% 10000007 + fn(n-5)% 10000007 + fn(n-6)% 10000007)% 10000007 ;
}
int main() {
    long long n, caseno = 0, cases;
    //freopen("input.txt","r",stdin);
    scanf("%lld", &cases);
    while( cases-- ) {
        memset(dp,-1,sizeof dp);
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n)%10000007);
    }
    return 0;
}
