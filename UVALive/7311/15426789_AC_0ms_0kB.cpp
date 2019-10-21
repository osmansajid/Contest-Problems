#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long a=0,b=0,c=0;
    while(t--){
        long long x,y,z;
        cin>>x>>y>>z;
        a+=x;
        b+=y;
        c+=z;
        long long res=min(min(a,b),c);
        if(res>=30){
            cout<<res<<endl;
            a-=res;
            b-=res;
            c-=res;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
