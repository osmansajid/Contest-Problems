#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,mini=999999999,ans=0,f=0,f2=0;
    cin>>n>>k;
    int a[n+10],b[n+10],c[n+10],d[n+10];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    while(k!=0){
        for(int i=0;i<n;i++){
            if(b[i]+k<a[i]){
                f2=2;
                break;
            }
            else if(b[i]-a[i]>=0)b[i]=b[i]-a[i];
            else{
                 int x=a[i]-b[i];
                 if(k-x>=0){
                    b[i]=0;
                    k=k-x;
                 }
                 else{
                    f=1;
                    break;
                 }
            }
            if(f==1){
                break;
            }
        }
        if(f2==2 || f==1) break;
        ans++;
    }
    cout<<ans<<endl;
}
