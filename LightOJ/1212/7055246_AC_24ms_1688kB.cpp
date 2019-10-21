#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        int n,m,l,c=0;
        string s;
        cin>>n>>m;
        deque <int> q;
        printf("Case %d:\n",i);
        for(j=1;j<=m;j++)
        {
            cin>>s;
            if(s=="pushLeft")
            {
                cin>>l;
                if(c==n)
                {
                   printf("The queue is full\n");
                }
                else
                {
                  c++;
                  q.push_front(l);
                  printf("Pushed in left: %d\n",l);
                }
            }
            else if(s=="pushRight")
            {
                cin>>l;
                if(c==n)
                {
                   printf("The queue is full\n");
                }
                else
                {
                  c++;
                  q.push_back(l);
                  printf("Pushed in right: %d\n",l);
                }
            }
            else if(s=="popLeft")
            {
                if(q.empty())
                {
                    printf("The queue is empty\n");
                }
                else
                {
                    c--;
                    printf("Popped from left: %d\n",q.front());
                    q.pop_front();
                }
            }
            else if(s=="popRight")
            {
                if(q.empty())
                {
                    printf("The queue is empty\n");
                }
                else
                {
                    c--;
                    printf("Popped from right: %d\n",q.back());
                    q.pop_back();
                }
            }
        }
        q.clear();
    }
}
