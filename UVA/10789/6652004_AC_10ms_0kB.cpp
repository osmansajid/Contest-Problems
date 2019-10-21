#include<bits/stdc++.h>
using namespace std;
#define n 2010
bool prime[n];
void seive()
{
    int  i,j;
    for(i=0;i<=n;i++)
    {
        prime[i]=1;
    }
    prime[0]=0;
    prime[1]=0;
    for(i=2;i*i<=n;i++)
    {
        for(j=i*i;j<=n;j=j+i)
        {
            prime[j]=0;
        }
    }
}
int main()
{
    string a;
    int t,i;

    seive();
    scanf("%d",&t);
    getchar();
    for(int k=1;k<=t;k++)
    {
        getline(cin,a);
    int c[100],j,count,max=0,flag=0;
    string b="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for(i=0;i<b.size();i++)
    {
        count=0;
        for(j=0;j<a.size();j++)
        {
            if(a[j]==b[i])
            {
                count++;
            }
        }
       // printf("%d\n",count);
        c[i]=count;

    }
    printf("Case %d: ",k);
    for(i=0;i<b.size();i++)
    {
        if(prime[c[i]])
        {
            if(i<10)
            {
             printf("%c",i+48);
             flag=1;
            }
            else if(i>=10 && i<=35)
            {
                printf("%c",i+55);
                flag=1;
            }
            else if(i>=36 && i<=61)
            {
                printf("%c",i+61);
                flag=1;
            }
        }
    }
    if(flag==0)
    {
        printf("empty");
    }

    printf("\n");


 }
}
