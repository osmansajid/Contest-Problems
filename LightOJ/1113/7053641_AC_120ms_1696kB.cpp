#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,flag;
    cin>>t;
    string a;
    string b;
    for(i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);
        stack<string>sf;
        stack<string>sb;
        stack<string>s;
        s.push("http://www.lightoj.com/");
        while(cin>>a)
        {
            flag=0;
            if(a=="BACK")
            {
                if(!sb.empty())
                {
                    sf.push(s.top());
                    s.push(sb.top());
                    sb.pop();
                }
                else
                {
                    flag=1;
                    printf("Ignored\n");
                }
            }
            else if(a=="FORWARD")
            {
                if(!sf.empty())
                {
                    sb.push(s.top());
                    s.push(sf.top());
                    sf.pop();
                }
                else
                {
                    flag=1;
                    printf("Ignored\n");
                }
            }
            else if(a=="VISIT")
            {
                cin>>b;
                sb.push(s.top());
                s.push(b);
                while(!sf.empty())
                {
                    sf.pop();
                }
            }
            else if(a=="QUIT")
            {
                break;
            }
            if(flag==0)
            {
             printf("%s\n",s.top().c_str());
            }
        }
    }
}
