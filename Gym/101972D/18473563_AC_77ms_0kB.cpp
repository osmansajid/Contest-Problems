#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        int b=n/2 + 1;
        int w=n/2;
        if(b<=x && w<=y) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
