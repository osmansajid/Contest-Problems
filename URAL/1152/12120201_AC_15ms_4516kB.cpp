#include<bits/stdc++.h>
using namespace std;
int dp[(1<<20)+2],n,a[22];

int Set(int mask,int pos){
    return mask=mask|(1<<pos);
}
int reset(int mask,int pos){
    return mask=mask&~(1<<pos);
}
bool check(int mask,int pos){
    return (bool)(mask&(1<<pos));
}

int fun(int mask,int pos){
    mask=Set(mask,pos);
    if(pos==0){
        if(check(mask,1)==false)mask=Set(mask,1);
        if(check(mask,n-1)==false)mask=Set(mask,n-1);
    }
    else if(pos==n-1){
        if(check(mask,n-2)==false)mask=Set(mask,n-2);
        if(check(mask,0)==false)mask=Set(mask,0);
    }
    else{
        if(check(mask,pos-1)==false)mask=Set(mask,pos-1);
        if(check(mask,pos+1)==false)mask=Set(mask,pos+1);
    }
    return mask;
}
int call(int mask)
{
    if(mask==(1<<n)-1){
        return 0;
    }
    if(dp[mask]!=-1){
        return dp[mask];
    }
    int mini=1<<28;
    for(int i=0;i<n;i++){
        if(check(mask,i)==false){
            int res=0;
            for(int j=0;j<n;j++){
                if(i!=0 && i!=n-1){
                    if(check(mask,j)==false && j!=i && j!=i+1 && j!=i-1){
                        res+=a[j];
                    }
                }
                else if(i==0){
                    if(check(mask,j)==false && j!=0 && j!=1 && j!=n-1){
                        res+=a[j];
                    }
                }
                else{
                    if(check(mask,j)==false && j!=i && j!=0 && j!=n-2){
                        res+=a[j];
                    }
                }
            }
            res=res+call(fun(mask,i));
            mini=min(mini,res);
        }
    }
    return dp[mask]=mini;
}

int main()
{
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<call(0)<<endl;
}
