#include<bits/stdc++.h>
using namespace std;
#define siz  10000
bool marked[siz];
long long primes[siz];
int n,ans[1010],answ[1010];
int j;
  /*******************************/
 /*********PRIME_SEIVE***********/
/*******************************/
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
  /*******************************************/
 /*********NOD_NUMBER_OF_DIVISORS************/
/*******************************************/
int NOD(int n)
{
    int res=1;
    for(int i=0;i<j;i++)
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
void Fals_order()
{
    int i,j,maxi=35,temp;
    for(i=1;i<=1000;i++)
    {
        ans[i]=NOD(i);
    }
    for(i=1;i<=1000;i++)
    {
        for(j=1;j<=1000;j++)
        {
            if(ans[j]<=maxi)
            {
                maxi=ans[j];
                temp=j;
            }
        }
        answ[i]=temp;
        ans[temp]=35;
        maxi=35;
    }
}
int main()
{
    int t,cs=0;
    seive();
    Fals_order();
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<"Case "<<++cs<<": "<<answ[n]<<endl;
    }
}
