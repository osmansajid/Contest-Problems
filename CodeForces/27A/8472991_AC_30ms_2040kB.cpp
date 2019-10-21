#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+10];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<=3000;i++){
        if(a[i]!=i+1){
            cout<<i+1<<endl;
            break;
        }
    }
}
