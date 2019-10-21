#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        cout<<"Case "<<++tc<<": ";
        if((c1%2!=0 && r1%2!=0) ||(r1%2==0 && c1%2==0)){
            if(c2%2==0 && r2%2!=0){
                cout<<"impossible"<<endl;
            }
            else if(c2%2!=0 && r2%2==0){
                cout<<"impossible"<<endl;
            }
            else if(abs(r1-r2)==abs(c1-c2)){
            cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
        else if((r1%2==0 && c1%2!=0)||(r1%2!=0 && c1%2==0)){
            if(r2%2==0 && c2%2==0){
                cout<<"impossible"<<endl;
            }
            else if(r2%2!=0 && c2%2!=0){
                cout<<"impossible"<<endl;
            }
            else if(abs(r1-r2)==abs(c1-c2)){
            cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
    }
}
