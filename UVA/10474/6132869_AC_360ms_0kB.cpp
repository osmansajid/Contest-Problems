#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,i,j,flag,l,k;
    int a[10000];
    int b[10000];
    for(l=1;l<=65 ;l++)
    {
        scanf("%d %d",&n,&q);
        if(n==0 && q==0)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<q;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a,a+n);
        printf("CASE# %d:\n",l);
        for(i=0;i<q;i++)
        {

            flag=0;
            for(k=0;k<n;k++)
            {
                if(b[i]==a[k])
                {
                    printf("%d found at %d\n",b[i],k+1);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("%d not found\n",b[i]);
            }
        }

    }
}
