#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,aa=0,gg=0;
    cin>>n;
    int a[n+10],g[n+10];
    for(int i=0;i<n;i++){
        cin>>a[i]>>g[i];
    }
    for(int i=0;i<n;i++){
        if(aa+a[i]-gg<=500){
            cout<<'A';
            aa+=a[i];
        }
        else{
            cout<<'G';
            gg+=g[i];
        }
    }
}
