#include <stdio.h>
#include <string.h>
int main()
{
    int t,i,p,r=0;
    char c[100];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
     scanf("%s",&c);
     if(strcmp(c,"donate")==0)
     {
     scanf("%d",&p);
     r=r+p;
     }
     else
     {
     printf("%d\n",r);
     }
}
}
