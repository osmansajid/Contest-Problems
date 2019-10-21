#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt=0;
    cin>>n;
    int x[n+10],y[n+10];
    for(int i=0;i<n;i++){
        cin>>x[i];
        cin>>y[i];
    }
    for(int i=0;i<n;i++){
        int f1=0,f2=0,f3=0,f4=0;
        for(int j=0;j<n;j++){
            if((x[i]>x[j] && y[i]==y[j])){
                f1=1;
            }
            if((x[i]<x[j] && y[i]==y[j])){
                f2=1;
            }
            if((x[i]==x[j] && y[i]>y[j])){
                f3=1;
            }
            if(x[i]==x[j] && y[i]<y[j]){
                f4=1;
            }
        }
        //cout<<cnt<<endl;
        if(f1==1&& f2==1 && f3==1 &&f4==1){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}