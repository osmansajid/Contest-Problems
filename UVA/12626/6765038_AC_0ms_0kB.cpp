#include<bits/stdc++.h>
using namespace std;
int  main()
{
    int n,m,a,r,g,t,i,j,k;
    string l;
    cin>>n;
    getchar();
    for(j=0;j<n;j++)
    {
      getline(cin,l);
      m=0,a=0,r=0,g=0,t=0,i=0;
        for(k=0;k<l.size();k++)
        {
            if(l[k]=='A')
            {
                a++;
            }
            else if(l[k]=='M')
            {
                m++;
            }
            else if(l[k]=='R')
            {
                r++;
            }
            else if(l[k]=='G')
            {
                g++;
            }
            else if(l[k]=='T')
            {
                t++;
            }
            else if(l[k]=='I')
            {
                i++;
            }
        }
        cout<<min(min(min(min(min(a/3,m),r/2),g),i),t)<<endl;

    }
}
