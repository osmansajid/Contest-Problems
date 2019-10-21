#include<bits/stdc++.h>
using namespace std;
map< int, map< int, map<int, int> > > mp;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--)
    {
        int n,counter=0;
        cin>>n;
        int a[n+10];
        //memset(mp,0,sizeof mp);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    //cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                    if(a[i]+a[j]>a[k] && mp[a[i]][a[j]][a[k]]==0)
                    {
                        counter++;
                        //cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                        mp[a[i]][a[j]][a[k]]++;
                    }
                }
            }
        }
        cout<<"Case #"<<++tc<<": "<<counter<<endl;
        mp.clear();
    }
}
