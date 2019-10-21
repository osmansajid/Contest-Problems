#include <stdio.h>
int main()
{
    long long a,b,i,p;
    scanf("%lld %lld",&a,&b);
    p=0;
   for(i=a;i<=b;i++)
   {
       if(i%2!=0)
       {
           p=p+i;
       }
   }
   printf("%lld",p);
}
