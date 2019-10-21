#include<bits/stdc++.h>
using namespace std;
#define mod 2000000011

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        long long n,ans=1;
        cin>>n;
        for(int i=1;i<=n-2;i++){
            ans=(ans%mod * n%mod)%mod;
        }
        cout<<"Case #"<<++tc<<": "<<ans<<endl;
    }
}
