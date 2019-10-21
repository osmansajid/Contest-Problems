#include<bits/stdc++.h>
using namespace std;

struct choco{
    int v,id;
};

bool operator <(choco x,choco y){
    return x.v<y.v;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        choco a[n+m];
        for(int i=0;i<n-1;i++){
            cin>>a[i].v;
            a[i].id=1;
        }
        for(int i=n-1;i<n+m-2;i++){
            cin>>a[i].v;
            a[i].id=2;
        }
        sort(a,a+m+n-2);
        int ver=1,hor=1,ans=0;
        for(int i=m+n-3;i>=0;i--){
            if(a[i].id==1){
                ans+=a[i].v*hor;
                //cout<<a[i].v<<" "<<hor<<endl;
                ver++;
            }
            else{
                ans+=a[i].v*ver;
                //cout<<a[i].v<<" "<<ver<<endl;
                hor++;
            }
        }
        cout<<ans<<endl;
    }
}
