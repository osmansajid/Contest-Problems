#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i,p,j,k,x,count,l;
    char b[10000];
    char a[10000];
    while(gets(a))
    {
        x=strcmp("DONE",a);
   if(x==0)
   {
       break;
   }
        j=0;
        p=strlen(a);
        for(i=0;i<p;i++)
        {
            if((a[i]>=65 && a[i]<=90) || (a[i]>=97 && a[i]<=122))
            {
                b[j]=tolower(a[i]);
                j++;
            }
        }
        count=0;
        for(i=0,k=j-1;i<j && k>=0;i++,k--)
        {
            if(b[i]!= b[k])
            {
                printf("Uh oh..\n");
                break;
            }
           count++;

        }
        if(count==j)
        {
            printf("You won't be eaten!\n");
        }

    }


}
