#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,x,flag=0;
    cin>>n>>m;
    int a[n+10];
    memset(a,0,sizeof a);
    for(int i=0;i<m;i++){
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            cout<<i<<" ";
            flag=1;
        }
    }
    if(flag==0) cout<<"*";
}
