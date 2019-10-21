#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000000000000

long long Pow(long long x,long long y){
   if(y==0) return 1;
   else if(y%2==0){
        long long a=Pow(x,y/2);
        return a*a;
   }
   else return x*Pow(x,y-1);
}

long long check(long long n){
    long long ans=0,i=1,x=1;
    while(x!=0){
        x=n/Pow(5,i);
        ans+=x;
        i++;
    }
    return ans;
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        printf("Case %d: ",++tc);
        long long hi=MAX,lo=0,ans=0,mid,ok;
        while(hi>lo){
            mid=(lo+hi)/2;
            ok=check(mid);
            if(ok>=n){
                if(ok==n){
                    ans=mid;
                }
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }
        if(ans==0)printf("impossible\n");
        else printf("%lld\n",ans);
    }
}
