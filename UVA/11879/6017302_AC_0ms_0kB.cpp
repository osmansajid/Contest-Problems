#include <stdio.h>
#include <string.h>
int main()
{
    long long i,j,l,d,p,s;
    char a[10000];
    for(i=1;i<=10;i++)
    {
        scanf("%s",&a);
        l=strlen(a);
        p=0;
        if(a[0]=='0' && l==1)
        {
            break;
        }
        for(j=0;j<l;j++)
        {
            s=p*10+a[j]-'0';
            p=s%17;
        }
        if(p==0)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }

    }
}
