#include<bits/stdc++.h>
using namespace std;
#define INF 999999999
int l,n,a[51],dp[1010][1010];

int call(int left,int right){
    if(left>=right) return 0;
    if(right-left==1) return 0;
    if(dp[left][right]!=-1) return dp[left][right];
    int res=INF;
    for(int i=left+1;i<right;i++){
        res=min(res,call(i,right)+call(left,i)+a[right]-a[left]);
    }
    return dp[left][right]=res;
}
int main()
{
    while(cin>>l){
        if(!l) return 0;
        memset(dp,-1,sizeof dp);
        cin>>n;
        a[0]=0,a[n+1]=l;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<"The minimum cutting is "<<call(0,n+1)<<"."<<endl;
    }
}
