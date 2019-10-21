#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,cnt=0,f=0,i;
    cin>>n>>m;
    int a[1010];
    for(i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==m){
            f=1;
        }
    }
    if(f==0){
        a[i]=m;
        n=n+1;
        cnt++;
        i++;
    }
    sort(a,a+n);
    int mid=(n+1)/2;
    while(a[mid-1]!=m){
        if(a[mid-1]<m){
            a[i]=100000;
            n=n+1;
            cnt++;
            i++;
            mid=(n+1)/2;
        }
        else if(a[mid-1]>m){
            a[i]=1;
            n=n+1;
            cnt++;
            i++;
            mid=(n+1)/2;
        }
        sort(a,a+n);
        //cout<<a[mid-1]<<endl;
    }
    cout<<cnt<<endl;
}
