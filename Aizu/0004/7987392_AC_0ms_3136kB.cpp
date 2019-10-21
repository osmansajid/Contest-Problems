#include<bits/stdc++.h>
using namespace std;
int main()
{
    float a,b,c,d,e,f;
    while(cin>>a>>b>>c>>d>>e>>f)
    {
        float x,y,p,q,m,n;
        m=((c*d)-(f*a));
        p=((b*d)-(e*a));
        x=m/p;
        n=((c*e)-(f*b));
        q=((a*e)-(d*b));
        y=n/q;
        if(x==-0) x=0;
        if(y==-0) y=0;
        printf("%.3f %.3f\n",y,x);
    }
}
