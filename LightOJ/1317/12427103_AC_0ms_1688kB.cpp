#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        double n,m,k,p;
        scanf("%lf %lf %lf %lf",&n,&m,&k,&p);
        printf("Case %d: %lf\n",++tc,(n*(1.0/m)*p*k)*m);
    }
}
