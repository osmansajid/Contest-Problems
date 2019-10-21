#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,n;
    vector<long long>v;
    while(cin>>n)
    {
        v.push_back(n);
    }
    for(i=v.size()-1;i>=0;i--)
    {
        printf("%.4lf\n",sqrt(v[i]));
    }
}
