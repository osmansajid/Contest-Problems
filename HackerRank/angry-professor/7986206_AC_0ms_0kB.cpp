#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,s=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int j;
            cin>>j;
            if(j<=0)
            {
                s++;
            }
        }
        if(s>=k)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
}
