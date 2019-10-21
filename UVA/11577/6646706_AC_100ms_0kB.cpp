#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int t;
    scanf("%d",&t);
    getchar();
    for(int k=1;k<=t;k++)
    {
        getline(cin,a);
    int c[26],i,j,count,max=0;
    string b="abcdefghijklmnopqrstuvwxyz";
    for(i=0;i<b.size();i++)
    {
        count=0;
        for(j=0;j<a.size();j++)
        {
            a[j]=tolower(a[j]);
            if(a[j]==b[i])
            {
                count++;
            }
        }
       // printf("%d\n",count);
        c[i]=count;

    }
    max=c[0];
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            if(c[i]>max)
            {
                max=c[i];
            }
        }
    }
    for(i=0;i<26;i++)
    {
        if(c[i]==max)
        {
            printf("%c",i+97);
        }
    }
    printf("\n");
    }

}
