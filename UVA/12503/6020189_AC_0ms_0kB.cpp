#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,p,n,k,m,s,e;
    int b[150];
    char c[40];
    char a[40];
    scanf("%d",&t);
    while(t--)
    {
        p=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%s",a);
            if(strcmp(a,"LEFT")==0)
            {
                p=p-1;
                b[i]=-1;

            }
            else if(strcmp(a,"RIGHT")==0)
            {
                p=p+1;
                b[i]=1;
            }
            else
            {
                scanf("%s%d",a,&s);
                p=p+b[s];
                b[i]=b[s];
            }
        }
        printf("%d\n",p);
    }
}
