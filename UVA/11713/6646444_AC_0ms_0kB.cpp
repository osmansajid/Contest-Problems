#include <stdio.h>
#include <string.h>
int main()
{
    int p,n,m,i,j,t,k,count;
    char a[1000];
    char b[1000];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s",&a);
        p=strlen(a);
        scanf("%s",&b);
        n=strlen(b);
        for(j=0;j<p;j++)
        {
            if(a[j]=='a' || a[j]=='e' || a[j]=='i' || a[j]=='o' ||a[j]=='u')
            {
                a[j]='a';
            }
        }
        for(k=0;k<p;k++)
        {
            if(b[k]=='a' || b[k]=='e' || b[k]=='i' || b[k]=='o' || b[k]=='u')
            {
                b[k]='a';
            }
        }


           count=0;
            for(j=0,k=0;j<p && k<n;j++,k++)
            {
                if(a[j]!=b[k])
                {
                    printf("No\n");
                    break;
                }
                if(p!=n)
         {
           printf("No\n");
           break;
         }

                count++;
            }
            if(count==p)
            {
                printf("Yes\n");
            }


        }
    }

