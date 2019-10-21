#include<stdio.h>
int a[2000000],b[2000000],c[2000000];
int main()
{
    int n,i=0,k,j,r=0,l=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&a[i],&b[i]);
        i++;
    }
    for(j=i-1;j>=0;j--)
    {
      if(j==0)
        {
            k=(a[j]+b[j])+r;
            c[l]=k;
            l++;
        }
       else
        {
         k=(a[j]+b[j]+r)%10;
         r=(a[j]+b[j]+r)/10;
         c[l]=k;
         //printf("%d %d\n",k,r);
         l++;
        }
    }
    for(i=l-1;i>=0;i--)
    {
        printf("%d",c[i]);
    }
   // printf("\n");
}
