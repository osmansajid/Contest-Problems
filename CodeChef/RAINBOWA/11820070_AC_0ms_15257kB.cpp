#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,f=0,x=0;
        cin>>n;
        int a[n],mp[11];
        memset(mp,0,sizeof mp);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>7) f=1;
            if(a[i]==7) x=i;
            mp[a[i]]++;
        }
        for(int i=1;i<=7;i++){
            if(mp[i]==0){
                f=1;
                break;
            }
        }
        for(int i=0,j=n-1;i<n&& j>=0;i++,j--){
            if(a[i]!=a[j]){
                f=1;
                break;
            }
        }
        for(int i=1;i<=x;i++){
            if(a[i]<a[i-1]){
                f=1;
                break;
            }
        }
        if(f==1) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
}
