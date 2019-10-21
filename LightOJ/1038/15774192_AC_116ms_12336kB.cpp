#include<bits/stdc++.h>
using namespace std;
double dp[100001];
vector<int> divisors[100001];

void div(){
    for(int i=2;i<100001;i++){
        for(int j=i;j<100001;j+=i){
            divisors[j].push_back(i);
        }
    }
}

double call(int n){
    if(n==1) return 0;
    if(dp[n]!=0.0) return dp[n];
    //int x=sqrt(n)+1;
    double nod=divisors[n].size()+1;
    double res=(double)(1.0/nod);
    for(int i=0;i<nod-1;i++){
        res+=(double)(1.0/nod)*(call(n/divisors[n][i])+1);
       // cout<<res<<endl;
    }
    return dp[n]=(double)(nod*res)/(double)(nod-1);
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    div();
    memset(dp,0.0,sizeof dp);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("Case %d: %lf\n",++tc,call(n));
    }
}
