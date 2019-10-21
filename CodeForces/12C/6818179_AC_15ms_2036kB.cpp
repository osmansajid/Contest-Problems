#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,max=0,i,min=0;
    string b;
    cin>>n>>m;
    priority_queue<int>pq;
    priority_queue<int>pqu;
    priority_queue<int>pquu;
    priority_queue<int>pquuu;
    queue<string>q;
    map<string,int>mp;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        pq.push(a);
        pquu.push(-a);
    }
    for(i=1;i<=m;i++)
    {
        cin>>b;
        if(mp.find(b)!=mp.end())
        {
            mp[b]++;
        }
        else
        {
            mp[b]=1;
            q.push(b);
        }
    }
        while(!q.empty())
        {
            pqu.push(mp[q.front()]);
            pquuu.push(mp[q.front()]);
            q.pop();
        }
        while(!pqu.empty())
        {
           max=max+pqu.top()*pq.top();
           pqu.pop();
           pq.pop();
        }
        while(!pquuu.empty())
        {
           min=min+(-pquu.top())*pquuu.top();
           //printf("%d %d\n",pquu.top(),pquuu.top());
           pquuu.pop();
           pquu.pop();
        }
        printf("%d %d",min,max);
}
