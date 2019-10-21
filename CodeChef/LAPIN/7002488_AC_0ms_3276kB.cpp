#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,j,flag=0;
        string a;
        cin>>a;
        map<int,int>mp;
        map<int,int>np;
        for(i=0;i<a.size()/2;i++)
        {
          mp[a[i]]++;
        }
        for(i=a.size()-1;i>(a.size()-1)/2;i--)
        {
          np[a[i]]++;
        }
        for(i='a';i<='z';i++)
        {
            if(mp[i]!=np[i])
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
}
