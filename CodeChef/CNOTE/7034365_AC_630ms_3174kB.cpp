#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,k,n,flag=0,i,p,c;
        cin>>x>>y>>k>>n;
        //int a[n+1];
        for(i=0;i<n;i++)
        {
            cin>>p>>c;
            if((p+y>=x && c<=k)||(y>=x))
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            printf("LuckyChef\n");
        }
        else
        {
            printf("UnluckyChef\n");
        }
    }
}
