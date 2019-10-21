#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,flag,ans;
    cin>>t;
    while(t--)
    {
        int n,i,j,k,max;
        cin>>n;
        int p[n+10];
        for(i=1;i<=n;i++)
        {
            int m,count=0;
            cin>>m;
            int a[m];
            for(j=0;j<m;j++)
            {
                cin>>a[j];
            }
            for(j=1;j<=6;j++)
            {
                for(k=0;k<m;k++)
                {
                    if(j==a[k])
                    {
                        count++;
                        break;
                    }
                }
            }
            if(count==4)
            {
                count=m+1;
            }
            else if(count==5)
            {
                count=m+2;
            }
            else if(count==6)
            {
                count=m+4;
            }
            else
            {
                count=m;
            }
            p[i]=count;
            //printf("%d %d\n",count,i);
        }
        max=p[1];
        ans=1;
        flag=0;
        for(i=2;i<=n;i++)
        {
            //printf("%d\n",p[i]);
            if(p[i]>max)
            {
                max=p[i];
                ans=i;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(p[i]==max && i!=ans)
            {
                printf("tie\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            if(ans==1)
            {
                printf("chef\n");
            }
            else
            {
                printf("%d\n",ans);
            }
        }
    }
}
