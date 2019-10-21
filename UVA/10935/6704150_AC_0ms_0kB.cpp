#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,m;
    queue <int> q;
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            break;
        }
    for(i=1;i<=n;i++)
    {
        int k;
        k=i;
        q.push(k);
    }
    printf("Discarded cards:");
    while(q.size()>1)
    {
        printf(" %d",q.front());
        q.pop();
        m=q.front();
        q.pop();
        if (!q.empty())
        {
          printf(",");
        }
        q.push(m);
    }
    printf("\nRemaining card: %d\n",q.front());
        q.pop();

 }
}
