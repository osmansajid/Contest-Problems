#include <stdio.h>
#include<string.h>
int main()
{
    int t,i,j,c;
    char a[10][110];
    int n[100];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        c=0;
        for(j=0;j<10;j++)
        {
            scanf("%s %d",&a[j],&n[j]);
            if(n[j]>c)
            {
               c=n[j];
            }
        }
        printf("Case #%d:\n",i);
        for(j=0;j<10;j++)
    {

        if(n[j]==c)
        {
            printf("%s\n",a[j]);
        }
    }
    }

}
