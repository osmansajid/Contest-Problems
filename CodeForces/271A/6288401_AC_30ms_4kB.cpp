#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long y,a,b,c,d,p;
    scanf("%I64d",&y);
    p=y;
    while(1)
    {
        p++;
        y=p;
        a=y%10;
        y=y/10;
        b=y%10;
        y=y/10;
        c=y%10;
        y=y/10;
        d=y%10;
        if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
        {
            printf("%I64d%I64d%I64d%I64d",d,c,b,a);
            break;
        }

    }
}
