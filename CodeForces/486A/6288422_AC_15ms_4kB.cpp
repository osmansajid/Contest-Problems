#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a;
    scanf("%I64d",&a);
    if(a%2==0)
    {
        printf("%I64d",a/2);
    }
    else
    {
        printf("%I64d",((a+1)/2)*(-1));
    }

}
