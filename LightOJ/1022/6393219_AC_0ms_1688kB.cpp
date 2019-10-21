#include <bits/stdc++.h>
#define pi 2 * acos (0.0)
using namespace std;
int main()
{
    double t,i,r,c,a,p;
    scanf("%lf",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf",&r);
        c=pi*r*r;
        a=(2*r)*(2*r);
        p=a-c;
        printf("Case %.0lf: %.2lf\n",i,p);
    }
}
