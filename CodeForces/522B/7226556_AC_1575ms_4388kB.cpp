#include<bits/stdc++.h>
using namespace std;
int w[200010],h[200010],a[200010];
int main()
{
    int n,cs=1,s=0,we,hi;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
        s+=w[i];
        cin>>h[i];
        a[i]=h[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        we=s-w[i];
        if(h[i]!=a[n-1])
        {
            hi=a[n-1];
        }
        else
        {
            hi=a[n-2];
        }
        cout<<we*hi<<endl;
    }
}
