#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        int n,j,k,count;
        map<int,string>mp;
        string a,b;
        cin>>n;
        for(j=1;j<=n;j++)
        {
            cin>>a;
            mp[j]=a;
        }
        cin>>b;
        printf("Case %d:\n",i);
        count=0;
        for(j=1;j<=n;j++)
        {
            count=0;
            for(k=0;k<mp[j].size();k++)
            {
                if(mp[j][k]!=b[k])
                {
                    count++;
                }
            }
            if(count==1 || count==0)
            {
                for(k=0;k<mp[j].size();k++)
                {
                    printf("%c",mp[j][k]);
                }
                printf("\n");
            }
        }
        mp.clear();
    }
}
