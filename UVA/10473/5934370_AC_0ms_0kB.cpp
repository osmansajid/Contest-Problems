#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
long int l,i,j,k,d,count,h;
char a[1000],b[100];
while(1)
{
gets(a);
l=strlen(a);

if(a[0]=='0' && a[1]=='x')
    {
    d=0;
    for(i=2;i<l;i++)
        {
        if(a[i]=='A')
        d=d*16+10;
        else if(a[i]=='B')
        d=d*16+11;
        else if(a[i]=='C')
        d=d*16+12;
        else if(a[i]=='D')
        d=d*16+13;
        else if(a[i]=='E')
        d=d*16+14;
        else if(a[i]=='F')
        d=d*16+15;
        else
        d=d*16+a[i]-'0';
        }
    printf("%ld\n",d);
    }


else
    {
    count=0;
    d=atoi(a);
    if(d<0)
{
 break;
}
    for(i=0;i!=-1;i++)
        {
        h=d%16;
        d/=16;
        if(h==10)
        b[i]='A';
        else if(h==11)
        b[i]='B';
        else if(h==12)
        b[i]='C';
        else if(h==13)
        b[i]='D';
        else if(h==14)
        b[i]='E';
        else if(h==15)
        b[i]='F';
        else
        b[i]=h+'0';
        count=count+1;
        if(d<=0)    break;
        }
    printf("0x");
    for(i=count-1;i>=0;i--)
    printf("%c",b[i]);
    printf("\n");
    }
}
return 0;
}
