#include<bits/stdc++.h>
using namespace std;
#define siz 1000000
bool marked[siz];
long long primes[siz];
long long j;
void seive()
{
    long long i;
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
        primes[0]=2;
        j=1;
        for(i=3;i<=siz;i+=2)
        {
            if(marked[i]==0)
            {
                primes[j]=i;
                j++;
            }
        }

}
long long Prime_NOD(long long n)
{
    long long res=1;
    //printf("%d\n",j);
    long long count=0;
    for(long long i=0;i<j;i++)
    {
        if(n%primes[i]==0)
         {
             //cout<<primes[i]<<" "<<n<<endl;
             count++;
             while(n%primes[i]==0)
             {
                 n/=primes[i];
             }
         }
    }
    return count;
}
int main()
{
    long long n;
    seive();
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        else
        {
            cout<<n<<" : "<<Prime_NOD(n)<<endl;
        }
    }
}

