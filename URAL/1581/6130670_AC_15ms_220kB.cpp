#include <stdio.h>
int main()
{
 int t,i,count=0;
 int  a[10000];
 scanf("%d",&t);
 for(i=0;i<t;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<t;i++)
        {
            if(a[i]==a[i+1])
            {
                count++;
            }
            else
            {
                 count++;
                 printf("%d %d ",count,a[i]);
                 count=0;
            }


        }
}
