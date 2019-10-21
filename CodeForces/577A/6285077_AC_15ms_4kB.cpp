#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,x,i,j,count=0;
    scanf("%I64d %I64d",&n,&x);
    for(i=1;i<=n;i++)
    {
            if (x%i==0 && x/i<=n)
             {
                 count++;
             }
    }
    printf("%I64d",count);
}
