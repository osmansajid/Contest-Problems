#include <stdio.h>
#include <string.h>
int main()
{
    int n,t,i,j,p,r,flag;
    char c[100];
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        scanf("%d",&t);
        flag=0;
        r=0;
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
      if(flag==0)
      {
          printf("Case %d:\n",j);
          flag=1;
      }
     printf("%d\n",r);
     }
    }
    }

}
