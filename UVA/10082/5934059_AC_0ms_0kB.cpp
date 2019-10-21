#include<stdio.h>
#include<string.h>
int main()
{
    int p,i;
    char a[100000];
   while( gets(a))
   {
    p=strlen(a);
    for(i=0;i<p;i++)
    {
        if(a[i]=='1')
        {
            printf("1");
        }
       else if(a[i]=='2')
        {
            printf("1");
        }
       else if(a[i]=='3')
        {
            printf("2");
        }
        else if(a[i]=='4')
        {
            printf("3");
        }
                else if(a[i]=='5')
        {
            printf("4");
        }
                else if(a[i]=='6')
        {
            printf("5");
        }
                else if(a[i]=='7')
        {
            printf("6");
        }
                else if(a[i]=='8')
        {
            printf("7");
        }
                else if(a[i]=='9')
        {
            printf("8");
        }
                else if(a[i]=='0')
        {
            printf("9");
        }
                else if(a[i]=='-')
        {
            printf("0");
        }
                else if(a[i]=='=')
        {
            printf("-");
        }
                else if(a[i]=='Q')
        {
            printf("Q");
        }
                else if(a[i]=='W')
        {
            printf("Q");
        }
                else if(a[i]=='E')
        {
            printf("W");
        }
                else if(a[i]=='R')
        {
            printf("E");
        }
                else if(a[i]=='T')
        {
            printf("R");
        }
                else if(a[i]=='Y')
        {
            printf("T");
        }
                else if(a[i]=='U')
        {
            printf("Y");
        }
                else if(a[i]=='I')
        {
            printf("U");
        }
                else if(a[i]=='O')
        {
            printf("I");
        }
                else if(a[i]=='P')
        {
            printf("O");
        }
                else if(a[i]=='[')
        {
            printf("P");
        }
                else if(a[i]==']')
        {
            printf("[");
        }
                else if(a[i]=='\\')
        {
            printf("]");
        }
                else if(a[i]=='A')
        {
            printf("A");
        }
                else if(a[i]=='S')
        {
            printf("A");
        }
                else if(a[i]=='D')
        {
            printf("S");
        }
                else if(a[i]=='F')
        {
            printf("D");
        }
                else if(a[i]=='G')
        {
            printf("F");
        }
                else if(a[i]=='H')
        {
            printf("G");
        }
                else if(a[i]=='J')
        {
            printf("H");
        }
                else if(a[i]=='K')
        {
            printf("J");
        }
                else if(a[i]=='L')
        {
            printf("K");
        }
                else if(a[i]==';')
        {
            printf("L");
        }
                else if(a[i]=='Z')
        {
            printf("Z");
        }
                else if(a[i]=='X')
        {
            printf("Z");
        }
                else if(a[i]=='C')
        {
            printf("X");
        }
                else if(a[i]=='V')
        {
            printf("C");
        }
                else if(a[i]=='B')
        {
            printf("V");
        }
                else if(a[i]=='N')
        {
            printf("B");
        }
                else if(a[i]=='M')
        {
            printf("N");
        }
                else if(a[i]==' ')
        {
            printf(" ");
        }
                else if(a[i]==',')
        {
            printf("M");
        }
                else if(a[i]=='.')
        {
            printf(",");
        }
                else if(a[i]=='/')
        {
            printf(".");
        }
            else if(a[i]==39)
        {
            printf(";");
        }

    }
    printf("\n");
}
}
