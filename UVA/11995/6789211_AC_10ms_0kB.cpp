#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>

#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    long long n,count,qu,pqu,st,i,a,b,c,flag;
   while(scanf("%lld",&n)==1)
   {
    stack<long long> s;
    queue<long long> q;
    priority_queue<long long>pq;
    flag=0;
    count=0,qu=0,pqu=0,st=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&a,&c);
        if(a==1)
        {
           q.push(c);
           s.push(c);
           pq.push(c);
        }
        else if(a==2)
        {
            count++;
            if(!q.empty()&&c==q.front())
            {
                qu++;
                q.pop();
            }
            if(!s.empty()&&c==s.top())
            {
                st++;
                s.pop();
            }
            if(!pq.empty()&&c==pq.top())
            {
                pqu++;
                pq.pop();
            }
        }
    }
        if((pqu==count&& st==count) || (pqu==count && qu==count) || (st==count&& qu==count) || (pqu==count&& st==count && qu==count))
        {
            printf("not sure\n");
        }
         else if(pqu==count)
        {
            printf("priority queue\n");
        }
        else if(qu==count)
        {
            printf("queue\n");
        }
        else if(st==count)
        {
            printf("stack\n");
        }
        else
        {
            printf("impossible\n");
        }
   }
   return 0;
}
