
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, p, q, m;
unsigned int SA, SB, SC;
ll s[5000010];
ll ans;
unsigned int rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
int main()
{
    int t;
    scanf("%d",&t);
    int k=0;
    while(t--)
    {
        k++;
        scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
        ll ans=0;
        int top=0;
 
        for(int i = 1; i <= n; i++)
        {
            if(rng61() % (p + q) < p)
            {
                //PUSH(rng61() % m + 1);
                ll res=rng61()%m+1;
                s[++top]=res;
                s[top]=max(s[top],s[top-1]);
            }
 
            else
            {
                // POP();
                top=max(top-1,0);
            }
 
            ans^=(s[top]*1LL*i);
        }
 
        printf("Case #%d: ",k);
        printf("%lld\n",ans);
 
    }
 
 
    return 0;
}
