#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    while(b!=0)
    {
        a=a%b;
        swap(a,b);
    }
    return a;
}
int main()
{
    int t,i,j,k,ans,n;
    int a[110];
    string s;
    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,s);
        n=0;
        j=0;
        for(i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                n=n*10+s[i]-'0';
            }
            if(s[i]==' ' || i==s.size()-1)
            {
                a[j]=n;
                j++;
                n=0;
            }
        }
        ans=1;
        for(i=0;i<j;i++)
        {
            //printf("%d ",a[i]);
            for(k=i+1;k<j;k++)
            {
                ans=max(ans,gcd(a[i],a[k]));
            }
        }
        cout<<ans<<endl;
    }
}

