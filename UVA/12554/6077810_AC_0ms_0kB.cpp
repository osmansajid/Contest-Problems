#include <stdio.h>
#include <string.h>
int main()
{
    int a,i,j,p,k=1;
    scanf("%d",&a);
    char b[a][105];
    for(j=0;j<a;j++)
    {
        scanf("%s",&b[j][105]);
    }
    if(a<=16)
    {
        for(j=1,i=0;i<16;j++,i++)
        {

           if(i==0 || i==4 || i==8 || i==12)
            {
                printf("%s: Happy\n",b[j]);
            }
           else if(i==1 || i==5 || i==9 || i==13)
            {
                printf("%s: birthday\n",b[j]);
            }
           else if(i==2 || i==6 || i==10 || i==14)
            {
                printf("%s: to\n",b[j]);
            }
           else if(i==3 || i==7 || i==15)
            {
                printf("%s: you\n",b[j]);
            }
           else if(i==11)
            {
                printf("%s: Rujia\n",b[j]);
            }
            if(j>=a)
            {
                j=0;
            }

        }
    }
    else
    {
        if(a%16!=0)
        {
            p=(a/16)+1;
        }
        else
        {
            p=a/16;
        }
         for(j=1,i=0;i<(16*p);j++,i++)
        {

           if(i%4==0)
            {
                printf("%s: Happy\n",b[j]);
            }
           else if(i%4==1)
            {
                printf("%s: birthday\n",b[j]);
            }
           else if(i%4==2)
            {
                printf("%s: to\n",b[j]);
            }
           else if(i%4==3 && (16*k)-i!=5)
            {
                printf("%s: you\n",b[j]);
            }
           else if(i%4==3 && (16*k)-i==5)
            {
                printf("%s: Rujia\n",b[j]);
                k++;
            }
            if(j>=a)
            {
                j=0;
            }

    }
}
}
