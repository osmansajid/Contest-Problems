#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,s=0,i;
    scanf("%d",&n);
    int c[n];
    for(i=0;i<(n-1);i++)
    {
        scanf("%d",&c[i]);
    }
    scanf("%d %d",&a,&b);
    for(i=a-1;i<b-1;i++)
    {
        s=s+c[i];
    }
    printf("%d",s);
}
