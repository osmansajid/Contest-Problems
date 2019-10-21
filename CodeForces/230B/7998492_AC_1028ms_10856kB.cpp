#include<bits/stdc++.h>
using namespace std;
#define siz  1000000
bool marked[siz];
long long primes[siz];
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
        for(j=i*i;j<=siz;j=j+i)
        {
            marked[j]=1;//marking all multiples of odd primes
        }
    }

}
int main()
{
    long long n,p,t;
    cin>>t;
    seive();
    while(t--)
    {
        cin>>n;
        p=sqrt(n);
        if(p*p==n)
        {
            if(marked[p]==0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            printf("NO\n");
        }
    }
}
