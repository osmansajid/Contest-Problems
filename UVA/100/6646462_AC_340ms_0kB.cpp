#include<stdio.h>
int main()
{
    int a,b,i,n,k,count,max;
    while(scanf("%d %d",&a,&b)==2)
    {   max=0;
    printf("%d %d ",a,b);
        if(a>b)
        {
            k=b;
            b=a;
            a=k;
        }
        for(i=a;i<=b;i++)
        {    n=i;
            count=0;
            while(n)
            {
                if(n==1)
                {
                    count++;
                    break;

                }
                else if(n%2==0)
                {
                    count++;
                    n=n/2;
                }
                else if(n%2!=0 && n!=1)
                {
                    count++;
                    n=(3*n)+1;
                }
            }
            if(count>max)
            {
                max=count;
                count=0;
            }

        }
        printf("%d\n",max);
    }
    return 0;
}
