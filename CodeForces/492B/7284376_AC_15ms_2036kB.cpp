#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l;
    cin>>n>>l;
    float s=0,max=0;
    int i,a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        if(i==0 && a[i]!=0)
        {
          max=float(a[i]);
        }
        else if(i==n-1 && a[i]!=l)
        {
            s=float(l-a[n-1]);
        }
        else if(i==n-1 && a[i]==l)
        {
           continue;
        }
        else
        {
          s=float(a[i+1]-a[i])/2.00;
        }
        if(s>max)
        {
            max=s;
        }
        //printf("%f\n",max);
    }
        if(a[n-1]!=l)
    {
        s=float(l-a[n-1]);
    }
    if(s>max)
    {
        max=s;
    }
    printf("%.10f\n",max);
}
