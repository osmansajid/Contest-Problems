#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,p=1,count=0;
        cin>>n;
        for(i=1;i<=n;i+=p)
        {
            count++;
            p++;
        }
        printf("%d\n",count);
    }
}
