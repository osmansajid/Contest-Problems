#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,count=0,i,flag=0;;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int s=0;
        for(i=0;i<n;i++)
        {
            if(a[i]<2)
            {
                printf("-1\n");
                flag=1;
                break;
            }
            else
            {
                if(i==0)
                {
                    s+=2;
                }
                else
                {
                    s+=a[i];
                }
            }
        }
        if(flag==0)
        {
            printf("%d\n",s);
        }
    }
}
