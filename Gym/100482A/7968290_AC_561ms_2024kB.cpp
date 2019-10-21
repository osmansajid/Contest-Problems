#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
        }
        if(n==1) cout<<"Case #"<<++tc<<": "<<"1"<<endl;
        else cout<<"Case #"<<++tc<<": "<<"2"<<endl;
    }
}
