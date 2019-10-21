#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[1010];
    scanf("%s",a);
    int p,i,j,flag=0;
    p=strlen(a);
    for(i=0,j=p-1;i<p&&j>=0;i++,j--)
    {
        if(p%2!=0 && i==((p+1)/2)-1)
        {
            if(a[i]=='A'|| a[i]=='I' || a[i]=='o' || a[i]=='O' || a[i]=='v' || a[i]=='V' ||a[i]=='M' || a[i]=='w' || a[i]=='W' || a[i]=='x'|| a[i]=='X' || a[i]=='Y' || a[i]=='T' || a[i]=='U'|| a[i]=='H')
            {
                continue;
            }
            else
            {
                printf("NIE");
                flag=1;
                break;

            }
        }
       else if( a[i]==a[j] && (a[i]=='A'|| a[i]=='I' || a[i]=='o' || a[i]=='O' || a[i]=='v' || a[i]=='V' ||a[i]=='M' || a[i]=='w' || a[i]=='W' || a[i]=='x'|| a[i]=='X' || a[i]=='Y' || a[i]=='T' || a[i]=='U'||a[i]=='H'))
        {
            continue;
        }
        else if((a[i]=='b'&&a[j]=='d')|| (a[i]=='p'&&a[j]=='q')||(a[i]=='d'&&a[j]=='b')||(a[i]=='q'&&a[j]=='p'))
        {
            continue;
        }
        else
        {
            printf("NIE");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("TAK");
    }
}
