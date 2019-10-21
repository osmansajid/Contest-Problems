#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int a,b,c,d,e,count=0;
        cin>>a;
        if(a==n)
        {
            count++;
        }
         cin>>b;
        if(b==n)
        {
            count++;
        }
         cin>>c;
        if(c==n)
        {
            count++;
        }
         cin>>d;
        if(d==n)
        {
            count++;
        }
         cin>>e;
        if(e==n)
        {
            count++;
        }
        printf("%d\n",count);
    }
}
