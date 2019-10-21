#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,p,i,a,b,c,d,count;
    while(cin>>n>>m)
    {
        count=0;
        for(i=n;i<=m;i++)
        {
            p=i;
            if(p>10 && p<100)
            {
                a=p%10;
                b=p/10;
                if(a==b)
                {
                    count++;
                }
            }
            else if(p>=100 && p<1000)
            {
                a=p%10;
                p=p/10;
                b=p%10;
                c=p/10;
                //printf("%d %d %d\n",a,b,c);
                if(a==b || b==c || a==c)
                {
                    //printf("%d\n",i);
                    count++;
                }
            }
            else if(p>=1000)
            {
                a=p%10;
                p=p/10;
                b=p%10;
                p=p/10;
                c=p%10;
                d=p/10;
                if(a==b || a==c || a==d || b==c || b==d || c==d)
                {
                    //printf("%d",i);
                    count++;
                }
            }
        }
        cout<<m-n-count+1<<endl;
    }
}
