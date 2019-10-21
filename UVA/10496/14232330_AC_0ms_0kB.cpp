#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,b,posx[21],posy[21],dp[(1<<10)+2][21][21];

int Set(int mask,int pos){
    return mask=mask|(1<<pos);
}
int reset(int mask,int pos){
    return mask=mask&~(1<<pos);
}
bool check(int mask,int pos){
    return (bool)(mask&(1<<pos));
}

int call(int mask,int xx,int yy)
{
    if(mask==(1<<b)-1){
        //cout<<xx<<"ha "<<yy<<endl;
        return abs(x-xx)+abs(y-yy);
    }
    if(dp[mask][xx][yy]!=-1) return dp[mask][xx][yy];
    int res=1<<28;
    for(int i=0;i<b;i++){
        if(!check(mask,i)){

                int z=abs(posx[i]-xx)+abs(posy[i]-yy)+call(Set(mask,i),posx[i],posy[i]);
                //cout<<posx[i]<<" "<<posy[i]<<" "<<z<<" "<<mask<<endl;
                res=min(res,z);
                //cout<<res<<endl;
        }
    }
    return dp[mask][xx][yy]=res;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin>>n>>m;
        cin>>x>>y;
        cin>>b;
        for(int i=0;i<b;i++){
            cin>>posx[i]>>posy[i];
        }
        cout<<"The shortest path has length "<<call(0,x,y)<<endl;
    }
}
