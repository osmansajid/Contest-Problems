#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,i;
    scanf("%I64d %I64d",&n,&a);
    if(a<=(n+1)/2)
    {
        printf("%I64d",2*a-1);
    }
    else
    {
        printf("%I64d",2*(a-(n+1)/2));
    }
}
