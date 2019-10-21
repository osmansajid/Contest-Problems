#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,j=0,flag=0,r;
        cin>>n;
        while(n>0)
        {
            if(n%10==9)
            {
                printf("1\n");
                flag=1;
                break;
            }
            n=n-9;
            r=n%10;
            j++;
            if(r==9)
            {
                printf("%d\n",j+1);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("Impossible\n");
        }
    }
}
