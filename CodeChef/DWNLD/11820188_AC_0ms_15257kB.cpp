#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int n,m,c=0,s=0,ans=0;
        cin>>n>>m;
        int a[1010];
        for(int i=1;i<=n;i++){
            int t,d;
            cin>>t>>d;
            for(int j=c;j<c+t;j++){
                a[j]=d;
            }
            c+=t;
        }
        for(int i=m;i<c;i++){
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
}
