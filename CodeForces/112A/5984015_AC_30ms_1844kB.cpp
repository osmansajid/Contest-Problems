#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i,j,p,k,count;
    char a[1000];
    char b[1000];
    char c[1000];
    char d[1000];
    gets(a);
    gets(b);
    p=strlen(a);
    j=0;
    k=0;
    count=0;
    for (i=0;i<p;i++)
    {
        c[j]=tolower(a[i]);
        j++;
    }
     for (i=0;i<p;i++)
    {
        d[k]=tolower(b[i]);
        k++;
    }
    for(i=0,j=0;i<p && j<p;i++,j++)
    {
        if(c[i]==d[j])
        {
            count++;
        }
        else if(c[i]>d[j])
        {
            printf("1\n");
            break;
        }
        else if(c[i]<d[j])
        {
            printf("-1\n");
            break;
        }
    }
    if(count==p)
    {
        printf("0\n");
    }
    return 0;
}
