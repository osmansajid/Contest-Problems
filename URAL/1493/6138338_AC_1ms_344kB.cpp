#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=0,b=0,i,d,e,f,g;
    char c[6];
    gets(c);
    for(i=0;i<=2;i++)
    {
        a=a+c[i]-'0';
    }
    for(i=3;i<6;i++)
    {
        b=b*10+c[i]-'0';
    }
    d=b+1;
    e=b-1;
    f=0;
    while(d!=0)
    {
        f=f+d%10;
         d=d/10;
    }
    g=0;
    while(e!=0)
    {
        g=g+e%10;
         e=e/10;
    }
    if(g==a)
    {
        printf("Yes");
    }
    else if(f==a)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}
