#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x,y,z;
    while(cin>>x>>y>>z){
        if(x==0 && y==0 && z==0)break;
        double rat1,rat2;
        rat1=y/x;
        rat2=z/y;
        if(rat1==rat2){
            cout<<"GP "<<z*rat1<<endl;
        }
        else{
            cout<<"AP "<<z+(z-y)<<endl;
        }
    }
}
