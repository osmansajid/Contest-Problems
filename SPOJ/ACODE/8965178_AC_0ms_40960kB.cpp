#include<bits/stdc++.h>
using namespace std;
int dp[5010];

int fun(int indx,string s)
{
    if(indx>=s.size()){
        return 1;
    }
    if(dp[indx]!=-1){
        return dp[indx];
    }
    int res1=0,res2=0;
    if(s[indx]=='0'){
       return 0;
    }
    res1+=fun(indx+1,s);
    if(indx!=s.size()-1){
        int temp=(s[indx]-48)*10+(s[indx+1]-48);
        if(temp<=26){
            res2+=fun(indx+2,s);
        }
    }
    return dp[indx]=res1+res2;
}
int main()
{
  string s;
  while(cin>>s){
    if(s[0]=='0'){
        break;
    }
    memset(dp,-1,sizeof dp);
    int ans=fun(0,s);
    cout<<ans<<endl;
  }
}

