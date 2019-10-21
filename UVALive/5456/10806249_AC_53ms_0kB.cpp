#include<bits/stdc++.h>
using namespace std;

int dp[15][15],dir[15][15],num,n;

int mcm(int a[],int i,int j){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini=INT_MAX;
    int ret;
    for(int k=i;k<j;k++){
        ret=mcm(a,i,k)+mcm(a,k+1,j)+a[i-1]*a[k]*a[j];
        if(ret<=mini){
            mini=ret;
            dir[i][j]=k;
        }
    }
    return dp[i][j]=mini;
}

void print(int i,int j){
    if(i==j){
        printf("A%d",num);
        num++;
        return;
    }
    printf("(");
    print(i,dir[i][j]);
    printf(" x ");
    print(dir[i][j]+1,j);
    printf(")");
}

int main()
{
    int tc=0;
    while(scanf("%d",&n)){
        if(n==0) break;
        memset(dp,-1,sizeof dp);
        memset(dir,0,sizeof dir);
        int a[n+10];
        scanf("%d %d",&a[0],&a[1]);
        for(int i=2;i<=n;i++){
            int b,c;
            scanf("%d %d",&b,&c);
            a[i]=c;
        }
        long long ans=mcm(a,1,n);
        num=1;
        printf("Case %d: ",++tc);
        print(1,n);
        printf("\n");
    }
}
