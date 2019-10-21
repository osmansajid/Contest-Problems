#include<bits/stdc++.h>
using namespace std;
int main()
{
    float r,n,tc=1;
    while(cin>>r>>n)
    {
        if(r==0 && n==0)
        {
            break;
        }
        else
        {
            float a=ceil(r/n)-1;
            if(a<=26)
            {
                cout<<"Case "<<tc++<<":"<<" "<<a<<endl;
            }
            else
            {
                cout<<"Case "<<tc++<<":"<<" "<<"impossible"<<endl;
            }
        }
    }
}
