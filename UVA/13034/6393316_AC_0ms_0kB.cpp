#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j;
    int a[14];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int flag=0;
        for(j=0;j<13;j++)
        {
            scanf("%d",&a[j]);
        }
        for(j=0;j<13;j++)
        {
            if(a[j]<=0)
            {
                printf("Set #%d: No\n",i);
                flag=1;
                 break;
            }
        }
        if(flag==0)
        {
            printf("Set #%d: Yes\n",i);
        }
    }
}
