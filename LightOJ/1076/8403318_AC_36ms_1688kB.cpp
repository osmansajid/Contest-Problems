#include<bits/stdc++.h>
using namespace std;
bool check(int n,int m,int a[],int maxc)
{
    int cn=1,cp=0;
    for(int i=0;i<n;i++){
        if(a[i]>maxc){
            return 0;
        }
        if(cp+a[i]>maxc){
            cp=0;
            cn++;
        }
        if(cn>m){
            return 0;
        }
        cp+=a[i];
    }
    return 1;
}
int main()
{
    int n,t,tc=0;
    cin>>t;
    //freopen("input.txt","r",stdin);
    while(t--){
        int m,n,hi=0,lo=1,mid,ans;
        cin>>n>>m;
        int a[n+10];
        for(int i=0;i<n;i++){
            cin>>a[i];
            hi+=a[i];
        }
        //cout<<hi<<endl;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(check(n,m,a,mid)){
                //cout<<mid<<endl;
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;
    }
}

