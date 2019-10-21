#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        double a,b,c;
        cin>>a>>b>>c;
        double lo=a/2.0,hi=1000000.0,mid,newa,s,theta;
        newa=(1+b*c)*a;
        if(newa==a){
            printf("Case %d: 0\n",++tc);
        }
        else{
            while(fabs(lo-hi)>EPS){
                mid=(hi+lo)/2.0;
                theta=acos((2*mid*mid-a*a)/(2.0*mid*mid));
                s=mid*theta;
                if(s>newa){
                    lo=mid;
                }
                else{
                    hi=mid;
                }
            }
            double x,y,z;
            x=(a)/2.0;
            y=mid;
            z=sqrt(y*y-x*x);
            printf("Case %d: %.8lf\n",++tc,y-z);
        }
    }
}
