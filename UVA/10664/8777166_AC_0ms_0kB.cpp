#include<bits/stdc++.h>
using namespace std;
int dp[21][2010];
int a[21],n,sum;

int call(int indx,int make)
{
    if(indx>=n){
        return 0;
    }
    if(dp[indx][make]!=-1) return dp[indx][make];
    int p1=0,p2=0;
    if(make+a[indx]<=sum){
        p1=a[indx]+call(indx+1,make+a[indx]);
    }
    p2=call(indx+1,make);
    return dp[indx][make]=max(p1,p2);
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        memset(a,0,sizeof a);
        memset(dp,-1,sizeof dp);
        string s;
        getline(cin,s);
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                a[j]=a[j]*10+(s[i]-'0');
            }
            else{
                j++;
            }
        }
        j++;
        n=j;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        int ss=sum;
        sum=sum/2;
        int ans=call(0,0);
        if((ss-ans)-ans==0) printf("YES\n");
        else printf("NO\n");
    }
}
