#include<bits/stdc++.h>
using namespace std;
#define p 1000008
bool primes[p];
long long a[p];
long long k=1;
void seive()
{
    long long i,j;
    for(i=0;i<=p;i++)
    {
        primes[i]=1;
    }
    primes[0]=0;
    primes[1]=0;
    for(i=2;i*i<=p;i++)
    {
        for(j=i*i;j<=p;j=j+i)
        {
            primes[j]=0;
        }
    }
    for(i=2;i<=p;i++)
    {
        if(primes[i]==1)
        {
            a[k]=i;
            k++;
        }
    }
}
int main()
{
    long long t=0,s,n,i,r,g,b,h,flag;
    long double count;
    seive();
    while(scanf("%lld",&n)==1)
    {
        t++;
        flag=0;
        if(n==0)
        {
            break;
        }
            for(i=1;i<=n;i++)
            {
                b=i;
                s=1;
                for(g=1;g<=k++&& a[g]<=sqrt(b);g++)
                {
                    count=0;
                    h=a[g];
                    if(b%a[g]==0)
                    {
                        while(b%a[g]==0)
                        {
                            count++;
                            b=b/a[g];
                            if(b==0||b==1)
                            {
                                break;
                            }
                        }
                        s=s*(pow((double)h,count+1)-1)/(h-1);
                    }

                }

               if(b!=1)
            {
                s=s*(pow((double)b,2)-1)/(b-1);
            }
                if(n==s)
                {
                   flag=1;
                   r=i;
                }
            }
            if(flag==1)
            {
                printf("Case %lld: %lld\n",t,r);
            }
            else if(flag==0)
            {
                printf("Case %lld: -1\n",t);
            }
        }
}

