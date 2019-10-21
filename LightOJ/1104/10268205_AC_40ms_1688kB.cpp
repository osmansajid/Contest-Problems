#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        double n,i;
        scanf("%lf",&n);
        double ans=1.0;
        for(i=n;i>=0;i--){
            ans*=(i/n);
            //cout<<ans<<endl;
            if(ans<=.500) break;
        }
        printf("Case %d: %.0lf\n",++tc,n-i);
    }
}
