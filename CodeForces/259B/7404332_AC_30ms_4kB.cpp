#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[4][4],p=0,q=0,r=0,s=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
            if(i==0)
            {
                p+=a[i][j];
            }
            if(i==1)
            {
                q+=a[i][j];
            }
            if(i==2)
            {
                r+=a[i][j];
            }
            s+=a[i][j];
        }
    }
     for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]==0 && i==0)
            {
                cout<<(s-2*p)/2<<" ";
            }
            else if(a[i][j]==0 && i==1)
            {
                cout<<(s-2*q)/2<<" ";
            }
             else if(a[i][j]==0 && i==2)
            {
                cout<<(s-2*r)/2<<" ";
            }
            else
            {
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }

 }

