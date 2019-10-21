#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,p=0,c;
    scanf("%I64d",&n);
    if(n==1)
    {
        printf("1");
    }
    else
    {
        for(i=1;i<n;i++)
    {
        c=(n-i)*i;
        p=p+c;
        if(i==n-1)
        {
            p=p+n;
        }
    }
    printf("%I64d",p);
    }

}
