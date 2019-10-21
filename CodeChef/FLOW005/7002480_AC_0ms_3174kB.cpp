#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,r,h,f,te,tw,fi,o;
        cin>>n;
        h=n/100;
        r=n-(h*100);
        f=r/50;
        r=r-(f*50);
        te=r/10;
        r=r-(te*10);
        fi=r/5;
        r=r-(fi*5);
        tw=r/2;
        r=r-(tw*2);
        o=r/1;
        cout<<h+f+te+fi+tw+o<<endl;
    }
}
