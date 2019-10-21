#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b<c) cout<<"Impossible"<<endl;
    else if(min(a,b)<=c){
        if(a<b)cout<<min(a,b)<<" "<<c-min(a,b)<<endl;
        else cout<<c-min(a,b)<<" "<<min(a,b)<<endl;
    }
    else{
        cout<<c/2<<" "<<c-(c/2)<<endl;
    }
}
