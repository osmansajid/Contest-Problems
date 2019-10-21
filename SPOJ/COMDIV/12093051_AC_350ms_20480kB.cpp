#include<bits/stdc++.h>
using namespace std;
#define siz  1000000
bool marked[siz];
int primes[siz];
int j;

void seive()
{
    int i;
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
    primes[0]=2;
    j=1;
    for(i=3;i<=siz;i+=2)
    {
        if(marked[i]==0)
        {
            primes[j]=i;//storing prime numbers in an array
            j++;
        }
    }
}


int NOD(int n)
{
    int res=1;
    for(int i=0;i<j && primes[i]<=sqrt(n);i++)
    {
        if(n%primes[i]==0)
         {
             int count=0;
             while(n%primes[i]==0)
             {
                 count++;//counting how many times a prime number has occurred in its factorization
                 n/=primes[i];
             }
             res*=(count+1);//(a+1)(b+1)(c+1)...here a,b,c.. are the powers of prime factors
         }
    }
    if(n!=1)
    {
        res=res*2;
    }
    return res;
}


int main()
{
    int t;
    scanf("%d\n",&t);
    seive();
    while(t--){
        int a,b,c,cnt=1;
        scanf("%d %d",&a,&b);
        c=__gcd(a,b);
        printf("%d\n",NOD(c));
    }
}
