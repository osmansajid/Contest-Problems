#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,ans1=0,ans2=0;
        cin>>n>>m;
        int a[n+1][m+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==-1) continue;
                else if((i+j)%2==0) ans1+=a[i][j];
                else ans2+=a[i][j];
            }
        }
        cout<<abs(ans1-ans2)<<endl;
    }
}
