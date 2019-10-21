#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,i,j;
    scanf("%d %d",&n,&t);
    char a[n];
    scanf("%s",&a);
    for(j=0;j<t;j++)
    {
        for(i=0;i<n;i++)
    {
        if(a[i]=='B' && a[i+1]=='G')
        {
            a[i]='G';
            a[i+1]='B';
            i=i+1;
        }
    }
    }
printf("%s",a);

}
