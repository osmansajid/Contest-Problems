#include<bits/stdc++.h>
using namespace std;

map<pair<int,int> ,string >m;

int main()
{
    int t;
    cin>>t;
    int tc=1;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        m[ make_pair(a,b) ]=s;
    }
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<m[ make_pair(a,b) ]<<endl;
    }
}
