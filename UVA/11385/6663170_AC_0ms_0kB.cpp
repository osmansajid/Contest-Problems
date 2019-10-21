#include<bits/stdc++.h>
using namespace std;
long long fib[102];
void fibo()
{
    long long k;
    long long i=1,j=1,f;
    fib[0]=1;
    for(k=1;k<102;k++)
        {
         f=i+j;
         i=j;
         j=f;
         fib[k]=j;
       }

}
int main()
{
 char a[110];
 char c[110];
 long long t,i,j,m,l,n,y;
 fibo();
 scanf("%lld",&t);
 getchar();
 for(y=1;y<=t;y++)
 {
     scanf("%lld",&n);
     long long b[n];
     for(j=0;j<n;j++)
     {
         scanf("%lld",&b[j]);
     }
     getchar();
     gets(a);
     char d[110];
     long long v=0;
     for(j=0;j<strlen(a);j++)
     {
         if(a[j]>='A' && a[j]<='Z')
         {
             d[v]=a[j];
             v++;
         }
     }
     long long m=0;
        for(l=0;;l++)
         {
            long long flag=0;
            for(j=0;j<n;j++)
           {
               if(fib[l]==b[j])
               {
                c[l]=d[j];
                m++;
                flag=1;
                break;
               }
           }
           if(flag==0)
           {
               c[l]=' ';
           }
           if(m==n)
           {
               break;
           }

         }
     for(j=0;j<=l;j++)
     {
         printf("%c",c[j]);
     }
     printf("\n");

 }
}
