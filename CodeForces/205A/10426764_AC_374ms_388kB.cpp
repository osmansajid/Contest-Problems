#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mini=INT_MAX,ans,cnt=0;
    cin>>n;
    int a[n+10];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(mini>a[i]){
            mini=a[i];
            ans=i+1;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==mini){
            cnt++;
        }
    }
    if(cnt>1){
        cout<<"Still Rozdil"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}
