#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            ans^=x;
        }
        if(ans==0) cout<<1<<endl;
        else cout<<0<<endl;
    }
}
