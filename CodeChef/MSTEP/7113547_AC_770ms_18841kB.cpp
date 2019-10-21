#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,s=0,j,p;
        map<int,int>mp;
        map<int,int>np;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&p);
                mp[p]=i;
                np[p]=j;
            }
        }
        for(i=2;i<=n*n;i++)
        {
            s+=(abs(mp[i]-mp[i-1])+abs(np[i]-np[i-1]));
        }
        printf("%d\n",s);
        mp.clear();
    }
}
