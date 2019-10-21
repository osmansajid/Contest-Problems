#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,cnt=0;
    cin>>n;
    long long a[n+10];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        a[i]=a[i]+cnt;
        if(a[i]<a[i-1]){
            cnt+=(a[i-1]-a[i]);
            a[i]=a[i-1];
        }
    }
    cout<<cnt<<endl;
}
