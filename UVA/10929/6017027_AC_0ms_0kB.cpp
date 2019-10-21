#include<stdio.h>
#include<string.h>
int main()
{
    long long i,j,l,b,c,d;
    char a[1010];
    while(1)
    {
        scanf("%s",&a);
        l=strlen(a);
        if(a[0]=='0' && l==1)
        {
            break;
        }
        c=0;
        for(i=0;i<l;i=i+2)
        {
            c=c+a[i]-'0';
        }
        d=0;
        for(j=1;j<l;j=j+2)
        {
            d=d+a[j]-'0';
        }
        b=c-d;
        if(b%11==0)
        {
            printf("%s is a multiple of 11.\n",a);
        }
        else
        {
            printf("%s is not a multiple of 11.\n",a);
        }
    }

}
