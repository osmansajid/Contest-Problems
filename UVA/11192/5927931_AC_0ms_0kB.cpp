#include<stdio.h>
#include<string.h>
int main()
{
    int a,p,n,i,c,j,temp;
    char b[105];
    while(scanf("%d",&a)==1 && a!=0)
    {
       scanf("%s",&b);
        p=strlen(b);
        n=p/a;
        for(i=0;i<p;i+=n)
        {
         c=i;
         j=(c+n)-1;
         while(c<j)
         {
             temp=b[c];
             b[c]=b[j];
             b[j]=temp;
             c++;
             j--;
         }

        }
        printf("%s\n",b);
    }
}
