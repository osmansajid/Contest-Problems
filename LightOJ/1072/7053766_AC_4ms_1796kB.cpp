#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265359
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
     double R,n,r;
     cin>>R>>n;
     r = R * sin(pi/n)/(1 + sin(pi/n));
     printf("Case %d: %lf\n",i,r);
    }
}
