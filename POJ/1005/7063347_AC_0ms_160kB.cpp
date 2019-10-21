#include<stdio.h>
#include<math.h>
#define pi 3.14159265359
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        double a,b;
        int y;
        scanf("%lf %lf",&a,&b);
        y=ceil(pi*(a*a+b*b)/100);
        printf("Property %d: This property will begin eroding in year %d.\n",i,y);
    }
    printf("END OF OUTPUT.\n");
}
