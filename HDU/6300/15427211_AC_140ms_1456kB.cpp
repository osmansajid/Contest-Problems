#include<bits/stdc++.h>
using namespace std;

struct point{
    int x,y,indx;
};

bool operator < (point a,point b){
    return a.x<b.x;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        point a[3*n+1];
        for(int i=0;i<n*3;i++){
            int xx,yy;
            cin>>xx>>yy;
            a[i].x=xx;
            a[i].y=yy;
            a[i].indx=i+1;
        }
        sort(a,a+3*n);
        for(int i=0;i<3*n;i+=3){
            //cout<<a[i].x<<" "<<endl;
            cout<<a[i].indx<<" "<<a[i+1].indx<<" "<<a[i+2].indx<<endl;
        }
    }
}
