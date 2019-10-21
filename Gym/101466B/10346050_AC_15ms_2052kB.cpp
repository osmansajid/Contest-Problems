#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long a[n+10];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long ans=1;
    long long temp=1;
    for(int i=n-1;i>=0;i--){
        temp=temp*a[i];
        ans+=temp;;
    }
    cout<<ans<<endl;
}
