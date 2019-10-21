#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c,i,j,k,flag=0,count=0;
    cin>>n>>m;
    int x[n+3];
    int y[m+3];
    string a[n+3];
    for(i=0;i<n;i++)
    {
        x[i]=0;
        cin>>a[i];
    }
    for(j=0;j<m;j++)
    {
            y[j]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
                if(a[i][j]=='*')
                {
                    count++;
                    y[j]++;
                    x[i]++;
                }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            int c=x[i]+y[j];
            if(a[i][j]=='*')
            {
                c--;
            }
            if(c==count)
            {
                printf("YES\n");
                printf("%d %d\n",i+1,j+1);
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    if(flag==0)
    {
        printf("NO\n");
    }
}
