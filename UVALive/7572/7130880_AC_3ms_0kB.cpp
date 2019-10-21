#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j;
    cin>>t;
    string s;
    for(j=1;j<=t;j++)
    {
        cin>>s;
        int a=0,b=0;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='a')
            {
                a++;
            }
            else
            {
                b++;
            }
        }
        if(a<b)
        {
            cout<<a<<endl;;
        }
        else if(a>b)
        {
            cout<<b<<endl;
        }
        else
        {
            cout<<a<<endl;
        }
    }
}
