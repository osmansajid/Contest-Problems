#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10000];
    int p,i;
    scanf("%s",a);
    p=strlen(a);
    if(a[0]>='a' && a[0]<='z')
    {
        a[0]=a[0]-32;
        printf("%c",a[0]);
        for(i=1;i<p;i++)
        {
            printf("%c",a[i]);
        }
    }
    else
    {
        printf("%s",a);
    }
}
