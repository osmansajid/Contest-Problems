#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,a[10][10];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                x=i;
                y=j;
            }
        }
    }
    cout<<abs(2-y)+abs(2-x)<<endl;
}
