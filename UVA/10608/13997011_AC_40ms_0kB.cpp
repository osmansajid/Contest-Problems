#include<bits/stdc++.h>
using namespace std;
#define N 30010
int pr[N];

int find(int r){
    return pr[r]= pr[r]==r?r:find(pr[r]);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        map<int,int>mp;
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            pr[i]=i;
        }
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            int x,y;
            x=find(a);
            y=find(b);
            if(x!=y){
                pr[x]=y;
            }
        }
        for(int i=1;i<=n;i++){
            mp[find(i)]++;
            ans=max(ans,mp[find(i)]);
        }
        cout<<ans<<endl;
    }
}
