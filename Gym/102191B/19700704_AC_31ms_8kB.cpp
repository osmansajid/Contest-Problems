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
    int b[10];
    for(int i=0;i<10;i++){
        cin>>b[i];
    }
    int ans=10;
    for(int i=0;i<n;i++){
        int flg=0;
        for(int j=0;j<10;j++){
            if(b[j]<=a[i]){
                flg=1;
            }
        }
        if(!flg)ans=min(ans,a[i]);
    }
    cout<<ans<<endl;
}
