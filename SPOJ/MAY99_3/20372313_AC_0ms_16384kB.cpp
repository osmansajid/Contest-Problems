#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if(x>y) swap(x,y);
        x=__gcd(x,y);
        if(z>y) cout<<"NO"<<endl;
        else if(z%x==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
