#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,y;
    cin>>b>>a;
    int x=b-a;
    y=x%10;
    if(y!=1){
        if(x/10!=0)cout<<x/10<<1<<endl;
        else cout<<1<<endl;
    }
    else{
        if(x/10!=0)cout<<x/10<<2<<endl;
        else cout<<2<<endl;
    }
}
