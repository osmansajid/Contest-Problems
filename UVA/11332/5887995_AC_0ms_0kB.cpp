#include <stdio.h>
int main()
{
 int a,p,q,r;
 while(scanf("%d",&a))
 {
 if(a != 0)
 {
     if(a<10)
     {
         printf("%d\n",a);
     }
    else if(a>9)
   {
    while(a>9)
   {  r=0;
     while(a>0)
    {
    p=a%10;
    q=a/10;
    r=r+p;
    a=q;
    }
    a=r;
   }
printf("%d\n",r);
   }
 }
 else
 {
     break;
 }
 }
}
