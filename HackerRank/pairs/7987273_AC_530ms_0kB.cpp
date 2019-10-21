#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,c=0;
    cin>>n>>k;
    int a[n];
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]=1;
    }
    for(int i=0;i<n;i++)
    {
        int p=a[i]+k;
        if(mp[p])
        {
            c++;
        }
    }
    cout<<c<<endl;
}
