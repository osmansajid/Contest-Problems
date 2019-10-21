#include<bits/stdc++.h>
using namespace std;
#define siz  1000001
bool marked[siz];
vector<long long >primes;
long long j;

void seive()
{
    long long i;
    for(i=4;i<=siz;i+=2)
    {
        marked[i]=1;//marking all even numbers
    }
    marked[1]=1;//as 1 is not a prime marked 1
    for(i=3;i*i<=siz;i+=2)
    {
        if(marked[i]==0)
        {
         for(j=i*i;j<=siz;j=j+i)
            {
                marked[j]=1;//marking all multiples of odd primes
            }
        }
    }
        primes.push_back(2);
        for(i=3;i<=siz;i+=2)
        {
            if(marked[i]==0)
            {
                primes.push_back(i);//storing prime numbers in an array
            }
        }

}
void fun()
{
    cout<<primes.size()<<endl;
}
int main()
{
    int t;
    scanf("%d",&t);
    seive();

    while(t--){
        long long a,b,cnt=0;
        scanf("%lld%lld",&a,&b);
        for(int i=0;i<primes.size();i++){
            //cout<<primes[i]<<endl;
            for(long long j=primes[i]*primes[i];j<=b;j*=primes[i]){
                //cout<<j<<endl;
                if(j>=a && j<=b) cnt++;
                //cout<<j<<endl;
            }
        }
        printf("%d\n",cnt);
    }
}