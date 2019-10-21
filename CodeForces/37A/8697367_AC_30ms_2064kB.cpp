#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,count=0,mx=0;
    cin>>n;
    int a[n];
    map<int ,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]]==1){
            count++;
        }
        if(mp[a[i]]>mx){
            mx=mp[a[i]];
        }
    }
    cout<<mx<<" "<<count<<endl;
}
