#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        long long n,m,s=0,sum1=0,sum=0,ans=0;
        cin>>n>>m;
        long long a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            s+=a[i];
            if(s>m){
                break;
            }
            else{
                sum1=s;
                sum+=s;
                ans++;
            }
        }
        cout<<"Case "<<++tc<<": "<<ans<<" "<<sum1<<" "<<sum<<endl;
    }
}
