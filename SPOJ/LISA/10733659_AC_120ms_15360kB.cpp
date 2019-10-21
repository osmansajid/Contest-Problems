#include<bits/stdc++.h>
#define MAX 999999999999999999
using namespace std;

long long dpmin[110][110],dpmax[110][110];

long long mcm(string s,int i,int j,int x){
    if(i==j){
        return (s[i]-'0');
    }
    if(dpmin[i][j]!=-1){
        return dpmin[i][j];
    }
    long long ret2;
    if(x==0) ret2=MAX;
    else ret2=0;
    long long ret=0;
    for(int k=i;k<j;k++){
        if(s[k]=='+'){
            ret=mcm(s,i,k-1,x)+mcm(s,k+1,j,x);
            if(x==0) ret2=min(ret2,ret);
            else ret2=max(ret2,ret);
        }
        else if(s[k]=='*'){
            ret=mcm(s,i,k-1,x)*mcm(s,k+1,j,x);
            if(x==0) ret2=min(ret2,ret);
            else ret2=max(ret2,ret);
        }
    }
    return dpmin[i][j]=ret2;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        memset(dpmin,-1,sizeof dpmin);
        long long mini=mcm(s,0,s.size()-1,0);
        memset(dpmin,-1,sizeof dpmin);
        long long maxi=mcm(s,0,s.size()-1,1);
        cout<<maxi<<" "<<mini<<endl;
    }
}
