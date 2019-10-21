#include<bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    int i,s;
    while(cin>>n)
    {
        if(n=="0")
        {
            break;
        }
        s=0;
         for(i=0;i<n.size();i++)
        {
            if(i%2==0)
            {
                s=s+n[i]-'0';
                //printf("%d\n",s);
            }
            else
            {
                s=s-n[i]+'0';
                //printf("%d %d\n",n[i],s);
            }
        }
        if(s%11==0)
        {
            cout<<n<<" is a multiple of 11."<<endl;
        }
        else
        {
            cout<<n<<" is not a multiple of 11."<<endl;
        }
    }
}
