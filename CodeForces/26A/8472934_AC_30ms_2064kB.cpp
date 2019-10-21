#include<bits/stdc++.h>
using namespace std;

#define siz  3000
bool marked[siz];
long long primes[siz];
long long j;
//finds prime numbers

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


//finds number of divisors

long long NOD(long long n)
{
    long long res=0;
    for(long long i=0;i<j;i++)
    {
        if(n%primes[i]==0)
         {
             res++;//(a+1)(b+1)(c+1)...here a,b,c.. are the powers of prime factors
         }
    }
    return res;
}

int main()
{
    seive();
    long long n,cnt=0;
    cin>>n;
    for(long long i=6;i<=n;i++){
        if(NOD(i)==2){
            //cout<<i<<endl;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
