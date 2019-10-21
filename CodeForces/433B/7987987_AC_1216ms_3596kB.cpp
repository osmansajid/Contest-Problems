#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,s=0,p=0;
    cin>>n;
    long long a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++)
    {
        s+=a[i];
        a[i]=s;
        //cout<<a[i]<<endl;
        p+=b[i];
        b[i]=p;
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int j;
        cin>>j;
        if(j==1)
        {
           long long q,r,d,e;
           cin>>q>>r;
           d=a[r-1];
           e=a[q-2];
           if(q==1) e=0;
           if(r==1) d=0;
           if(q==1 && r==1) d=a[0];
           cout<<d-e<<endl;
        }
        else
        {
           long long q,r,d,e;
           cin>>q>>r;
           d=b[r-1];
           e=b[q-2];
           if(q==1) e=0;
           if(r==1) d=0;
           if(q==1 && r==1) d=b[0];
           cout<<d-e<<endl;
        }
    }
}
