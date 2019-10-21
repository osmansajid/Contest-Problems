#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        int count=0,i,j;
        cin>>b>>a;
        for(i=0;i<a.size();i++)
        {
            for(j=0;j<b.size();j++)
            {
                if(a[i]==b[j])
                {
                    count++;
                    break;
                }
            }
        }
        cout<<count<<endl;
    }
}
