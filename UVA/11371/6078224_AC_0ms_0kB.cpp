#include <stdio.h>
#include <algorithm>
int main()
{
 long long a,i,num1,num2,r,j,k,m,temp,p,v;
 long long b[10000];
 long long c[10000];
 while(scanf("%lld",&a)==1)
 {
     i=0;
     while(a!=0)
     {
         m=a%10;
         a=a/10;
         b[i]=m;
         i++;
     }
    std::sort(b,b+i);

     for(k=0,j=i-1;k<i,j>=0;k++,j--)
     {
         temp=c[j];
         c[j]=b[k];

     }
     num2=0;
     for(j=0;j<i;j++)
     {
         num2=num2*10+c[j];

     }
     for(j=0;j<i;j++)
     {
         if(b[j]==0)
    {

    for(j=0;j<i;j++)
     {
         if(b[j]!=0)
     {
         v=b[j];
         b[0]=b[j];
         b[j]=0;
         break;

     }

     }
     break;
    }
     }

      num1=0;
     for(j=0;j<i;j++)
     {
         num1=num1*10+b[j];

     }
     r=num2-num1;
     p=r/9;
     printf("%lld - %lld = %lld = 9 * %lld\n",num2,num1,r,p);

 }
}
