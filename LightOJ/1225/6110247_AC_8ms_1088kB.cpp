#include <stdio.h>
int main()
{
    int t,i,m,j,b,c,p,count,k;
    int a[10000];
    k=0;
    scanf("%d",&t);
    for(p=1;p<=t;p++)
    {
       scanf("%d",&b);

    m=0;
    while(b!=0)
    {
        c=b%10;
        b=b/10;
        a[m]=c;
        m++;
    }
    count=0;
    for(i=0,j=m-1;i<m && j>=0;i++,j--)
    {
        if(a[i]!= a[j])
        {
            printf("Case %d: No\n",p);
            break;
        }
        count++;
    }
    if(count==m)
    {
        printf("Case %d: Yes\n",p);
    }
}
}