#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,count=0;
    char a[4];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",&a);
        if((a[0]=='X' &&a[1]=='+'&&a[2]=='+') || (a[0]=='+'&&a[1]=='+'&&a[2]=='X'))
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    printf("%d",count);
}
