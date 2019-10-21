#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+10][m+10];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    if(n%2!=0){
        cout<<n<<endl;
    }
    else{
        int f=0;
        while(n!=0){
            for(int i=0,k=n-1;i<n/2 && k>=n/2;i++,k--){
                for(int j=0;j<m;j++){
                    if(a[i][j]!=a[k][j]){
                        f=1;
                        break;
                    }
                }
                if(f==1){
                    break;
                }
            }
            if(f==1){
                break;
            }
            else{
                n=n/2;
                if(n%2!=0){
                    f=1;
                    break;
                }
            }
        }
        cout<<n<<endl;
    }
}
