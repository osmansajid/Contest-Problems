#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b && b!=c) cout<<"C"<<endl;
    else if(b==c && b!=a) cout<<"A"<<endl;
    else if(a==c && a!=b) cout<<"B"<<endl;
    else cout<<"*"<<endl;
}
