#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,b,end,begin,mid,i,flag=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>b;
        begin=0;
        end=n-1;
        flag=0;
        while(begin<=end)
        {
            mid=(begin+end)/2;
            if(b<=a[0])
            {
                printf("X ");
                flag=1;
                break;
            }
            if(b==a[mid])
            {
                end=mid-1;
            }
            else if(b>a[mid])
            {
                begin=mid+1;
            }
            else if(b<a[mid])
            {
                end=mid-1;
            }
        }
        if(flag==0)
        {
            printf("%d ",a[begin-1]);
        }
        begin=0;
        end=n-1;
        flag=0;
        while(begin<=end)
        {
            mid=(begin+end)/2;
            if(b>=a[n-1])
            {
                printf("X\n");
                flag=1;
                break;
            }
            if(b==a[mid])
            {
                begin=mid+1;
            }
            else if(b>a[mid])
            {
                begin=mid+1;
            }
            else if(b<a[mid])
            {
                end=mid-1;
            }
        }
        if(flag==0)
        {
            printf("%d\n",a[end+1]);
        }
    }
}
