#include <stdio.h>
int main()
{
 double T,x,y,z,i,n,l,p;
 scanf("%lf",&T);
 while(T--)
 {
     scanf("%lf %lf %lf",&x,&y,&z);
     n=(x+y)/3;
     l=x-n;
     p=l*z/n;
     printf("%.0lf\n",p);

 }
}