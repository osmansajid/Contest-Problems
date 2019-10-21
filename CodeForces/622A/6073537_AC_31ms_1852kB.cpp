#include <stdio.h>
int main()
{
    long long n,i;
    scanf("%I64d",&n);
    for(i=1;i<n;i++)
    {
        n=n-i;
    }
    printf("%I64d",n);
}
