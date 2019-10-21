#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
#define EPS 1e-9

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        char c;
        double a,b;
        scanf("%lf %c %lf",&a,&c,&b);
        double rperi=400.00;
        double lo=0.0,hi=200.0,mid,width,radi,theta,s,r,peri;
        while(fabs(lo-hi)>EPS){
            mid=(lo+hi)/2.0;
            width=(b*mid)/a;
            radi=sqrt((mid*mid)+(width*width));
            r=radi/2.0;
            theta=acos((r*r+r*r-(width*width))/(2.0*r*r));
            s=r*theta;
            peri=(2.0*s)+(2.0*mid);
            if(peri<rperi){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
        printf("Case %d: %.10lf %.10lf\n",++tc,mid,width);
    }
}
