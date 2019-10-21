#include<bits/stdc++.h>
using namespace std;
int dpmin[110][110],dpmax[110][110];

int mcm(string s,int i,int j,int x){
    if(i==j){
        return (s[i]-'0');
    }
    if(dpmin[i][j]!=-1){
        return dpmin[i][j];
    }
    int ret2;
    if(x==0) ret2=INT_MAX;
    else ret2=0;
    int ret=0;
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
        int mini=mcm(s,0,s.size()-1,0);
        memset(dpmin,-1,sizeof dpmin);
        int maxi=mcm(s,0,s.size()-1,1);
        cout<<maxi<<" "<<mini<<endl;
    }
}
