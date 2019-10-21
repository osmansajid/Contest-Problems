#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        long long c,s=0;
        c=a+b;
        //printf("%lld\n",c);
        while(c!=0)
        {
          c=c/10;
          s++;
        }
        printf("%d\n",s);
    }
}
