#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n+10];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(k<=n)cout<<a[n-k]<<" "<<0<<endl;
    else cout<<-1<<endl;
}
