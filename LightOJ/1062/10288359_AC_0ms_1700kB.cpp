#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        double x,y,c,a,p,q;
        cin>>x>>y>>c;
        a=min(x,y);
        double low=0,high=a,mid;
        while(high-low>0.0000000001){
            mid=(high+low)/2;
            p=sqrt(x*x-mid*mid);
            q=sqrt(y*y-mid*mid);
            //printf("%lf %lf\n",p,q);
            if(((1/p)+(1/q))==(1/c)){
                break;
            }
            else if(((1/p)+(1/q))>(1/c)){
                high=mid;
            }
            else{
                low=mid;
            }
        }
        printf("Case %d: %.10lf\n",++tc,mid);
    }
}
