#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[101][101],n,t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
                cin>>a[i][j];
        for(int i=n-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
        cout<<a[0][0]<<endl;
    }
}