#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    string b;
    string c;
    string d;
    cin>>a;
    cin>>b;
    cin>>d;
    c=a+b;
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    if(c==d)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}
