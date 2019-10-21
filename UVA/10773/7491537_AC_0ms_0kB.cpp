#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=1;
    cin>>t;
    while(t--)
    {
        float d,v,u,t1,t2,a;
        cin>>d>>v>>u;
        if(v>=u || u==0 || v==0)
        {
            printf("Case %d: can't determine\n",tc++);
        }
        else
        {
            t1=d/u;
            a=acos(v/u);
            t2=d/(u*sin(a));
            printf("Case %d: %.3f\n",tc++,t2-t1);
        }
    }
}
