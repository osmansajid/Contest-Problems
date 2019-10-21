#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    pair<int,int>pi;
    map<pair<int,int>,string>mp;
    string a;
    for(i=0;i<n;i++)
    {
        cin>>pi.first;
        cin>>pi.second;
        cin>>a;
        mp[pi]=a;
    }
    int t;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>pi.first;
        cin>>pi.second;
        if(mp.find(pi)!=mp.end())
        {
            cout<<mp[pi]<<endl;
        }
    }
}
