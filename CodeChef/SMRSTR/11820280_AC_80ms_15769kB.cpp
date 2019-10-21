#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        long long n,m,y,x=1;
        scanf("%lld %lld",&n,&m);
        long long a[n+10];
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            if(x<=1000000000)x*=a[i];
        }
        for(int i=0;i<m;i++){
            scanf("%lld",&y);
            printf("%lld ",y/x);
        }
        printf("\n");
    }
}
