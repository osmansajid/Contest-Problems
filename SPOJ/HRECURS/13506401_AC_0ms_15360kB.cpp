#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int tc=1;
    while(t--)
    {


        int n;
        cin>>n;
        int res=0;
        vector<int>odd;

        for(int i=1; i<=n; i++)
        {
            int p;
            cin>>p;
            res+=p;


        }
        printf("Case %d: %d\n",tc++,res);
    }
}
