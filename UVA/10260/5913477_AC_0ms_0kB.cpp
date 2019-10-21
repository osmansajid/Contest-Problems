#include <stdio.h>
#include<string.h>
int main()
{
    int i,p;
    char a[25];
   while (gets(a))
   {
    p=strlen(a);
    for(i=0;i< p;i++)
    {

        if((a[i]=='B' || a[i]=='F' || a[i]=='P' || a[i]=='V') &&(a[i+1]!='B' && a[i+1]!='F' && a[i+1]!='P' && a[i+1]!='V'))
        {
            printf("1");
        }
        else if((a[i]=='C' || a[i]=='G' || a[i]=='J' || a[i]=='K' || a[i]=='Q' || a[i]=='S' || a[i]=='X' || a[i]=='Z')&& (a[i+1]!='C' && a[i+1]!='G' && a[i+1]!='J' && a[i+1]!='K' && a[i+1]!='Q' && a[i+1]!='S' && a[i+1]!='X' && a[i+1]!='Z'))
        {
            printf("2");
        }
        else if((a[i]=='D' || a[i]=='T')&&(a[i+1]!='D' && a[i+1]!='T'))
        {
            printf("3");
        }
        else if((a[i]=='L')&&(a[i+1]!='L'))
        {
            printf("4");
        }
        else if((a[i]=='M' || a[i]=='N')&&(a[i+1]!='M' && a[i+1]!='N'))
        {
            printf("5");
        }
        else if((a[i]=='R')&&(a[i+1]!='R'))
        {
            printf("6");
        }
        else
        {
            continue;
        }

    }
 printf("\n");

}

}
