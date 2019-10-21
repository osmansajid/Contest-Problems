#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,flag=0;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b>c && b+c>a && c+a>b){
            continue;
        }
        else{
            flag=1;
        }
    }
    if(flag==1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
