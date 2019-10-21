#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n+n+1;j++){
            if(i==0){
               if(j==0 || j==n-1 || j>n){
                    cout<<"*";
               }
               else{
                    cout<<" ";
               }
            }
            else if(i==n-1){
                if(j==n+n || j==n+1 || j<n){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
            else {
                if(j==0 || j==n-1 || j==n+1 || j==n+n){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
}
