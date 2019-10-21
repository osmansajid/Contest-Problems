#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s,e;
    cin>>n>>s>>e;
    string st;
    cin>>st;
    if(st[s-1]==st[e-1]){
        cout<<0<<endl;
        return 0;
    }
    else{
        cout<<1<<endl;
        return 0;
    }
}
