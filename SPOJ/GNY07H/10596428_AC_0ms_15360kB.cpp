#include<bits/stdc++.h>
using namespace std;
int dp[4][51][16];

int call(int r,int c,int mask){
    if(r>4) return 0;
    if(c<0) return mask==0;//
    if(r==4)return call(0,c-1,mask);//if we have visited every row of the column then move to next column
    if(dp[r][c][mask]!=-1) return dp[r][c][mask];
    int res=0;
    if(mask & (1<<r)){//if prev columns this pos is taken by vertical domino
        res+=call(r+1,c,(mask & ~(1<<r)));//if we take the prev columns this pos vertically then we can't occupy this pos and thus moving to next row and resetting mask for next column
    }
    else{//if this pos is taken by horizontal domino
        res+=call(r+1,c,(mask | (1<<r)));//we can occupy it vertically and setting mask
        if(!(mask & (1<<(r+1)))) res+=call(r+2,c,mask);//if the next pos is also is not occupied then we can take it horizontally
    }
    return dp[r][c][mask]=res;
}
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        int n;
        cin>>n;
        cout<<++tc<<" "<<call(0,n-1,0)<<endl;
    }
}
