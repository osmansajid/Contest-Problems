#include<bits/stdc++.h>
using namespace std;
#define siz  5000000
bool marked[siz+10];
long long primes[siz+10];
long long sumd[siz+10];
long long ans[siz+10];

void seive(){
    int i,j;
    for(i=4;i<=siz;i+=2){
        marked[i]=1;//marking all even numbers
        sumd[i]+=2;
    }
    marked[1]=1;//as 1 is not a prime marked 1
    sumd[2]=2;
    for(i=3;i<=siz;i+=2){
        if(marked[i]==0){
            sumd[i]+=i;
            for(j=i*2;j<=siz;j=j+i){
                marked[j]=1;//marking all multiples of odd primes
                sumd[j]+=i;
            }
        }
    }
    for(i=2;i<=siz;i++){
        if(marked[sumd[i]]==0){
            ans[i]=ans[i-1]+1;
        }
        else ans[i]=ans[i-1];
    }
}


int main()
{
    seive();
    int a,b;
    while(cin>>a){
        if(a==0)break;
        cin>>b;
        cout<<ans[b]-ans[a-1]<<endl;
    }
}
