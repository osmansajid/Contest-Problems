#include<bits/stdc++.h>
using namespace std;
double dp[1000010];
#define siz  1000010
bool marked[siz];
long long primes[siz];
long long tot[siz];
long long j;

void seive(){
    long long i;
    for(i=4;i<=siz;i+=2){
        marked[i]=1;//marking all even numbers
    }
    marked[1]=1;//as 1 is not a prime marked 1
    for(i=3;i*i<=siz;i+=2){
        if(marked[i]==0){
         for(j=i*i;j<=siz;j=j+i){
                marked[j]=1;//marking all multiples of odd primes
            }
        }
    }
    primes[0]=2;
    tot[2]=1;
    j=1;
    for(i=3;i<=siz;i++){
        if(marked[i]==0){
            primes[j]=i;//storing prime numbers in an array
            tot[i]=j+1;
            j++;
        }
        else{
                tot[i]=j;
        }
    }
}

double call(int n){
    if(n==1) return 0;
    if(dp[n]!=0.0) return dp[n];
    double nod=(double)tot[n];
    double cnt=0,res=0;
    for(int i=0;primes[i]<=n;i++){
        if(n%primes[i]==0){
            res+=call(n/primes[i]);
            cnt++;
        }
    }
    res=((res+nod)/cnt);
    return dp[n]=res;
}

int main()
{
    seive();
    int t,tc=0;
    scanf("%d",&t);
    memset(dp,0.0,sizeof dp);
    while(t--){
        int nn;
        scanf("%d",&nn);
        printf("Case %d: %.10lf\n",++tc,call(nn));
    }
}
