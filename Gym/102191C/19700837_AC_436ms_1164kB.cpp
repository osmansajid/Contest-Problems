#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=4){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i+=2){
        cout<<a[i]<<" ";
    }
    if(n%2){
        for(int i=2;i<n;i+=2){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i=2;i<n-2;i+=2){
            cout<<a[i]<<" ";
        }
        cout<<a[n]<<" "<<a[n-2]<<endl;
    }
}
