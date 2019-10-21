#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;
int main()
{
    int n;
    double s=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    if(n%2!=0)
    {
        for(int i=0;i<n;i+=2)
        {
            s+=a[i]*a[i];
        }
        for(int i=1;i<n;i+=2)
        {
            s-=a[i]*a[i];
        }
        s=PI*s;
    }
    else
    {
        for(int i=1;i<n;i+=2)
        {
            s+=a[i]*a[i];
        }
        for(int i=0;i<n;i+=2)
        {
            s-=a[i]*a[i];
        }
        s=PI*s;
    }
      printf("%.10lf",s);
}
