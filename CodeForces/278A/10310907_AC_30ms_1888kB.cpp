#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+10];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s,t,sum1=0,sum2=0;
    cin>>s>>t;
    if(s==t){
        cout<<0<<endl;
        return 0;
    }
    for(int i=s;;){
        if(i==t){
            break;
        }
        sum1+=a[i];
        if(i==n) i=1;
        else i++;
        //cout<<i<<" "<<t<<endl;
    }
    for(int i=t;;){
        if(i==s){
            break;
        }
        sum2+=a[i];
        if(i==n) i=1;
        else i++;
        //cout<<i<<" "<<s<<endl;
    }
    cout<<min(sum1,sum2)<<endl;
}
