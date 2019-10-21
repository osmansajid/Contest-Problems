#include <stdio.h>
int main()
{
 int a,b,c;
 while(scanf("%d %d %d",&a,&b,&c)==3)
{
 if(a==b && a!=c && b!=c)
 {
     printf("C\n");
 }
else if(b==c && b!=a && c!=a)
 {
     printf("A\n");
 }
else if(a==c && a!=b && c!=b)
 {
   printf("B\n");
 }
else
{
    printf("*\n");
}
}
}
