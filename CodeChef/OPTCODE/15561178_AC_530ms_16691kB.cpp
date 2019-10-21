#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        pair<int,int> a[n];
        for(int i=0;i<n;i++){
            int xx,yy;
            cin>>xx>>yy;
            a[i]=make_pair(yy,xx);
        }
        sort(a,a+n);
        int cnt =0,ans=0;
        map<int,int>mark;
        for(int i=n-1;i>=0;i--){
            if(mark[a[i].second]==0){
                mark[a[i].second]=1;
                ans+=a[i].first;
                cnt++;
            }
            if(cnt==3) break;
        }
        if(cnt==3) cout<<ans<<endl;
        else cout<<0<<endl;
    }

}
