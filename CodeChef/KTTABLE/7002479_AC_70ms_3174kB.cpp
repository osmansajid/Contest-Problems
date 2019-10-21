#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        int n,i,b,p=0,count=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
         cin>>a[i];
         if(i!=0)
         {
          a[i]=a[i]-p;
         }
         p+=a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b;
            if(b<=a[i])
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
}
