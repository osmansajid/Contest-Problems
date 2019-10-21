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

void print(int i,int j)
{
    if(dir[i][j]==-1){
        if(i!=a.size()){
            for(int k=i;k<a.size();k++) cout<<a[k];
        }
        if(j!=b.size()){
            for(int k=j;k<b.size();k++) cout<<b[k];
        }
        return;
    }
    else if(dir[i][j]==3){
        cout<<a[i];
        print(i+1,j+1);
    }
    else{
        if(dir[i][j]==1){
            cout<<b[j];
            print(i,j+1);
        }
        else{
            cout<<a[i];
            print(i+1,j);
        }
    }
}
int main()
{
    string c;
    while(cin>>c){
        memset(dp,-1,sizeof dp);
        memset(dir,-1,sizeof dir);
        a=c;
        reverse(c.begin(),c.end());
        b=c;
        int p=LCS(0,0);
        cout<<c.size()-p<<" ";
        print(0,0);
        cout<<endl;
    }
}
