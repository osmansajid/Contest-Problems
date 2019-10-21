#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,k,m,j,max;
    vector<int> q;
    //int a[10000000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        q.push_back(m);
    }
    scanf("%d",&k);
    for(i=0;i<q.size()-k+1;i++)
    {
        max=q[i];
        for(j=i;j<i+k;j++)
        {
            if(q[j]>=max)
            {
                max=q[j];
            }
        }
        printf("%d ",max);

    }
}
