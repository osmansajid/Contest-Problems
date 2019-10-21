#include<bits/stdc++.h>
using namespace std;
string a,b;
int dp[1010][1010],dir[1010][1010];

int LCS(int i,int j)
{
    if(i==a.size() || j==b.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res1=0,res2=0,res3=0;
    if(a[i]!=b[j]){
        res1=LCS(i,j+1);
        res2=LCS(i+1,j);
        if(res1>res2) dir[i][j]=1;
        else dir[i][j]=2;
        res3=max(res1,res2);
    }
    else{
        dir[i][j]=3;
        res3=1+LCS(i+1,j+1);
    }
    return dp[i][j]=res3;
}


int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        string c;
        cin>>c;
        memset(dp,-1,sizeof dp);
        memset(dir,-1,sizeof dir);
        a=c;
        reverse(c.begin(),c.end());
        b=c;
        int p=LCS(0,0);
        cout<<"Case "<<++tc<<": "<<c.size()-p<<endl;
        //print(0,0);
    }
}
