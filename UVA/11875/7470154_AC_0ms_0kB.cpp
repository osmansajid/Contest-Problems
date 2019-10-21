#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<"Case "<<tc<<": "<<a[n/2]<<endl;
        tc++;
    }
    return 0;
}
