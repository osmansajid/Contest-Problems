#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,p,r;
    while(cin>>n>>k)
    {
        p=n;
        while(n>=k)
        {
         r=n%k;
         n=n/k;
         p+=n;
         n=n+r;
        }
        printf("%d\n",p);
    }
}
