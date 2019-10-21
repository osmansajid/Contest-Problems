#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3][3],p=0,q=0,r=0,s=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
            s+=a[i][j];
            if(i==0)p+=a[i][j];
            else if(i==1)q+=a[i][j];
            else if(i==2)r+=a[i][j];
        }
    }
     for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]==0)
            {
                if(i==0)cout<<s/2-p<<" ";
                else if(i==1)cout<<s/2-q<<" ";
                else if(i==2)cout<<s/2-r<<" ";
            }
            else
            {
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;

    }
}
