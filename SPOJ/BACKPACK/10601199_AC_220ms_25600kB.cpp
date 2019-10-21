#include<bits/stdc++.h>
using namespace std;

int dp[65][4][10010],n;

struct product{
    int v,c,id;
}p[65];

vector< product > vec [65],vec2[65];

int call2(int i,int j,int v){
    if(j>=vec[i].size()){
        return call2(i+1,0,v);
    }
    if(i>=n){
        return 0;
    }
    if(dp[i][j][v]!=-1){
        return dp[i][j][v];
    }
    int res1=0,res2=0;
    if(v-vec[i][j].v>=0){
        res1+=vec[i][j].c+call2(i,j+1,v-vec[i][j].v);
    }
    if(j!=0)res2+=call2(i,j+1,v);
    else res2+=call2(i+1,0,v);
    return dp[i][j][v]=max(res1,res2);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        int v,j=1;
        cin>>v>>n;
        for(int i=1;i<=n;i++){
            product a;
            cin>>a.v>>a.c>>a.id;
            a.c=a.c*a.v;
            if(a.id!=0) vec2[a.id].push_back(a);
            else{
                a.id=i;
                vec[j].push_back(a);
                j++;
            }
        }
        for(int i=1;i<j;i++){
            for(int l=0;l<vec2[vec[i][0].id].size();l++){
                vec[i].push_back(vec2[vec[i][0].id][l]);
            }
        }
        cout<<call2(1,0,v)<<endl;
        for(int i=0;i<65;i++) vec[i].clear();
        for(int i=0;i<65;i++) vec2[i].clear();
    }
}
