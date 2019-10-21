#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c;
    cin>>a>>b;
    c=a-b;
    long long d;
    d=c%10;
    if(d==9)
        {
         cout<<c-1;
        }
    else if(d!=9)
        {
          cout<<c+1;
        }
}
 