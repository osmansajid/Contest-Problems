#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10000];
    int t,i,j;
    scanf("%d",&t);
    getchar();
    for(j=0;j<t;j++)
    {
    gets(a);
    int p;
    int l=strlen(a);
    p=sqrt(l);
    if((p*p)!= l)
    {
        printf("INVALID\n");
    }
    else
    {
     for(i=0;;)
    {
       printf("%c",a[i]);
        i=i+p;
        //printf("%d\n",i);
        if(i>=l)
        {
            i=i-l+1;
            //printf("%d\n",i);
        }
        if(i==(l-1))
        {
            printf("%c\n",a[i]);
            break;
        }
    }
    }
    }

}
