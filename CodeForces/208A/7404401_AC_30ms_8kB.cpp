#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int j=0,flag=0;
    for(int i=0;i<a.size();i++)
    {
       if(a[i]=='W'&&a[i+1]=='U'&&a[i+2]=='B' && flag==1)
       {
           cout<<" ";
           i+=2;
           flag=0;
       }
       else if(a[i]=='W'&&a[i+1]=='U'&&a[i+2]=='B' && flag==0)
       {
           i+=2;
           flag=0;
       }
       else
       {
           cout<<a[i];
           flag=1;
       }
    }
}
