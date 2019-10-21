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
    sort(a,a+n);
    int ans=a[n-1];
    for(int i=n-1;i>=0;i--){
        ans+=a[i];
    }
    cout<<ans<<endl;
}
