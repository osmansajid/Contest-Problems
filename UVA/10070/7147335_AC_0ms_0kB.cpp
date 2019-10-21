#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int mark=0,f,i,k,d,l1,l2,l3,h,b;
    while(cin>>s)
    {
        if(mark==1)
        {
            printf("\n");
        }
        mark=1,f=0,l1=0,l2=0,l3=0,h=0,b=0,k=0;
        for(i=0;i<s.size();i++)
        {
            d=s[i]-'0';
            l1=(l1*10+d)%4;
            l2=(l2*10+d)%100;
            l3=(l3*10+d)%400;
            h=(h*10+d)%15;
            b=(b*10+d)%55;
        }
        if((l1==0 &&l2!=0) || l3==0)
        {
            printf("This is leap year.\n");
            k=1;
            f=1;
        }
        if(h==0)
        {
            printf("This is huluculu festival year.\n");
            f=1;
        }
        if(k==1 && b==0)
        {
            printf("This is bulukulu festival year.\n");
        }
        if(f==0)
        {
            printf("This is an ordinary year.\n");
        }
    }
}

