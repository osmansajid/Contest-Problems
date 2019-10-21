#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,p;
    cin>>n;
    if(n<=2)
    {
        printf("-1\n");
    }
    else if(n%2!=0)
    {
        p=n*n;
        printf("%lld %lld\n",p/2,(p/2)+1);
    }
    else
    {
        p=n*n;
        printf("%lld %lld\n",(p/4)-1,(p/4)+1);
    }
}
