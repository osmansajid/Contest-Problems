#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    double  k,s;
    cin>>n>>k;
    int x[n],y[n];
    for(i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(i=1;i<n;i++)
    {
        s+=sqrt(((x[i]-x[i-1])*(x[i]-x[i-1]))+((y[i]-y[i-1])*(y[i]-y[i-1])));
    }
    s=(s*(k))/50.0;
    printf("%.9lf\n",s);
}
