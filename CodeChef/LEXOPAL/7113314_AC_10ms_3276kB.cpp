#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,j,flag=0;
        string a;
        cin>>a;
        if(a.size()%2==0)
        {
            for(i=0,j=a.size()-1;i<=a.size()/2;i++,j--)
            {
                if(a[i]!=a[j] && (a[i]!='.'&& a[j]!='.'))
                {
                    flag=1;
                }
                else if(a[i]==a[j] && (a[i]=='.'&& a[j]=='.'))
                {
                    a[i]='a';
                    a[j]='a';
                }
                else if(a[i]!=a[j] && a[i]=='.')
                {
                    a[i]=a[j];
                }
                 else if(a[i]!=a[j] && a[j]=='.')
                {
                    a[j]=a[i];
                }
            }
            if(flag==0)
            {
                cout<<a<<endl;
            }
            else
            {
                cout<<"-1"<<endl;
            }
        }
        else
        {
            for(i=0,j=a.size()-1;i<a.size()/2;i++,j--)
            {
                if(a[i]!=a[j] && (a[i]!='.'&& a[j]!='.'))
                {
                    flag=1;
                    break;
                }
                else if(a[i]==a[j] && (a[i]=='.'&& a[j]=='.'))
                {
                    a[i]='a';
                    a[j]='a';
                }
                else if(a[i]!=a[j] && a[i]=='.')
                {
                    a[i]=a[j];
                }
                 else if(a[i]!=a[j] && a[j]=='.')
                {
                    a[j]=a[i];
                }
            }
            if(a[a.size()/2]=='.')
            {
                a[a.size()/2]='a';
            }
            if(flag==0)
            {
                cout<<a<<endl;
            }
            else
            {
                cout<<"-1"<<endl;
            }
        }
    }
}
