#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        long long n,m,ans=0;
        cin>>n>>m;
        for(long long i=n;i>=m;i--){
            ans+=((n-i)+1);
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
}
