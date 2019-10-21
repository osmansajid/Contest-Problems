#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,p,c,d,q;
    scanf("%d",&a);
    if(a>=0)
    {
        printf("%d",a);
    }
    else
    {
        p=a/10;
        c=a%10;
        d=a/100;
        q=d*10+c;
        if(p>q)
        {
            printf("%d",p);
        }
        else
        {
            printf("%d",q);
        }
    }
}
