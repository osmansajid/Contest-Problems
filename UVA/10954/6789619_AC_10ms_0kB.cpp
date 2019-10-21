#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,s,p;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        priority_queue<int> pq;
        long long s=0,k,a,b,ans=0;
        for(i=0;i<n;i++)
        {
           cin>>k;
           pq.push(-k);
        }
        while(pq.size()>1)
        {
            a=-pq.top();
            pq.pop();
            b=-pq.top();
            pq.pop();
            s=a+b;
            pq.push(-s);
            ans=ans+s;
        }
        printf("%lld\n",ans);
    }
}
