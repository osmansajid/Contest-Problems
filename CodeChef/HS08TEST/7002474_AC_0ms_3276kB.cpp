#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    float b;
    cin>>n>>b;
    if(n>b)
    {
        printf("%.2f",b);
    }
    else if(n%5!=0)
    {
        printf("%.2f",b);
    }
    else
    {
        if(b-n-.5>0)
        {
         printf("%.2f",b-n-.5);
        }
        else
        {
            printf("%.2f",b);
        }
    }
}
