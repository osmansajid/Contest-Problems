#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>v;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            v.push_back(cnt);
            v.push_back(a[i-1]);
            cnt=1;
        }
        else cnt++;
    }
    v.push_back(cnt);
    v.push_back(a[n-1]);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
}
