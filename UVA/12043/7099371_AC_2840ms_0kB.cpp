#include<bits/stdc++.h>
using namespace std;
#define siz 2005
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
long long NOD(long long n)
{
    long long res=1;
    //printf("%d\n",j);
    for(long long i=0;i<j;i++)
    {
        if(n%primes[i]==0)
         {
             //cout<<primes[i]<<" "<<n<<endl;
             long long count=0;
             while(n%primes[i]==0)
             {
                 count++;
                 n/=primes[i];
             }
             res*=(count+1);
         }
    }
    if(n!=1)
    {
        res=res*2;
    }
    return res;
}
long long SOD(long long n)
{
    double res=1;
    //printf("%d\n",j);
    for(long long i=0;i<j;i++)
    {
        if(n%primes[i]==0)
         {
             //cout<<primes[i]<<" "<<n<<endl;
             long long count=0;
             while(n%primes[i]==0)
             {
                 count++;
                 n/=primes[i];
             }
             res*=(pow(primes[i],(count+1))-1)/(primes[i]-1);
         }
    }
    if(n!=1)
    {
        res*=(n+1);
    }
    return res;
}
int main()
{
    long long t,a,b,k,i;
    seive();
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        long long N=0;
        long long S=0;
        long long p;
        if(a%k==0)
        {
           p=a;
        }
        else
        {
           p=((a/k)+1)*k;
        }
       // cout<<p<<endl;
        for(i=p;i<=b;i=i+k)
        {
            N=N+NOD(i);
            S=S+SOD(i);
            //cout<<SOD(i)<<endl;
        }
        cout<<N<<" "<<S<<endl;
    }
}
