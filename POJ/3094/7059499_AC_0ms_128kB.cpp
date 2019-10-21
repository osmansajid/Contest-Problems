#include<stdio.h>
#include<string.h>
int main()
{
    char a[300];
    while(gets(a))
    {
        int n=0,i;
        if(a[0]=='#')
        {
            break;
        }
        else
        {
            for(i=0;i<strlen(a);i++)
            {
                if(a[i]>=65 && a[i]<=90)
                {
                    n+=(a[i]-64)*(i+1);
                }
              // printf("%d\n",n);
            }
        }
        printf("%d\n",n);
    }

}
