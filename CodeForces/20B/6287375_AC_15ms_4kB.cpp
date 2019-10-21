#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c,r1,r2,d;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a==0 && b==0 && c==0)
    {
        printf("-1");
    }
    else if(a==0 && b==0)
    {
        printf("0");
    }
    else if(a==0)
    {
        printf("1\n%.10lf",-c/b);
    }
    else
    {
        d=(b*b)-4*a*c;
        if(d<0)
        {
            printf("0");
        }
        else if(d==0)
        {
            printf("1\n%.10lf",-b/(2*a));
        }
        else
        {
        r1=(-b-sqrt((b*b)-4*a*c))/(2*a);
        r2=(-b+sqrt((b*b)-4*a*c))/(2*a);
        if(r1<r2)
        {
             printf("2\n%.10lf\n%.10lf\n",r1,r2);
        }
        else
        {
             printf("2\n%.10lf\n%.10lf\n",r2,r1);
        }
       }
    }

}

