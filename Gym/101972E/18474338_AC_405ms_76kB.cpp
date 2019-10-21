#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        char p[n+1];
        for(int i=1;i<=n;i++){
            cin>>p[i];
        }
        pair<char,int>pp[m+1];
        for(int i=1;i<=m;i++){
            char c;
            int x=0;
            cin>>c;
            if(c=='W') cin>>x;
            pp[i]=make_pair(c,x);
            //cout<<pp[i].first<<pp[i].second<<endl;
        }
        int see=k;

        int cnt=0,f=0;
        for(int i=1;i<=m;i++){
            if(pp[i].first=='W' && pp[i].second<=see && p[pp[i].second]=='S'){
                cnt++;
                see=max(pp[i].second,see);
            }
            else if(pp[i].first=='W'){
                see=max(pp[i].second,see);
            }
            else if(pp[i].first=='A'){
                see=n;
            }
        }
        cout<<cnt<<endl;
        //for(int )
    }
}
