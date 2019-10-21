#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,j;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        long long m,i,d=0;
        string n;
        cin>>n;
        cin>>m;
        if(n[0]=='-')
        {
            i=1;
        }
        else
        {
            i=0;
        }
        for(;i<n.size();i++)
        {
            d=d*10+n[i]-'0';
            d=d%m;
        }
        printf("Case %d: ",j);
        if(d==0)
        {
            printf("divisible\n");
        }
        else
        {
            printf("not divisible\n");
        }
    }
}
