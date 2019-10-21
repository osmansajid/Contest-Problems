#include<bits/stdc++.h>
using namespace std;
#define siz 20000010
bool marked[siz];
long long primes_pair[siz];
void seive()
{
    long long i,j;
    for(i=4;i<=siz;i+=2)
    {
        marked[i]=1;
    }
    marked[1]=1;
    for(i=3;i*i<=siz;i+=2)
    {
        for(j=i*i;j<=siz;j=j+i)
        {
            marked[j]=1;
        }
    }

}
void twin_prime()
{
    long long j=1,i;
    for(i=3;i<=siz;i+=2)
    {
        if(marked[i]==0&& marked[i+2]==0)
        {
            primes_pair[j++]=i;
        }
    }
}
int main()
{
  long long a,i,d;
  seive();
  twin_prime();
  while(scanf("%lld",&a)==1)
  {
      printf("(%lld, %lld)\n",primes_pair[a],primes_pair[a]+2);
  }
}
