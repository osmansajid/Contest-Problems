#include<stdio.h>
int main()
{
    int t,d,p,i,j,k,f,count;
    scanf("%d",&t);

    for(j=1;j<=t;j++)
    {
        scanf("%d",&d);
        scanf("%d",&p);
        int a[p];
       for(i=0;i<p;i++)
        {
            scanf("%d",&a[i]);
        }
      count=0;
       for(f=1;f<=d;f++)
       {
               if(f%7!=0 && f%7!=6 )
               {
                for(i=0;i<p;i++)
                {
                    if(f%a[i]==0)
                    {
                        count++;
                        break;

                    }
                }

               }

            }

printf("%d\n",count);
        }


    }