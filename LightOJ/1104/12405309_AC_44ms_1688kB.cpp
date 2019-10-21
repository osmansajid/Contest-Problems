#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,i;
        double x=1.0;
        scanf("%d",&n);
        for(i=n;i>=0;i--){
            x*=(double)(i)/(double)(n);
            //cout<<x<<" "<<i<<" "<<n<<endl;
            double y=(1.0-x);
            if(y>=0.5){
                break;
            }
        }
        printf("Case %d: %d\n",++tc,n-i);
    }
}
