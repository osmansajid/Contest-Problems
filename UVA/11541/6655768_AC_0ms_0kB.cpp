#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int t,i,j,m;
    scanf("%d",&t);
    getchar();
    for( int l=1;l<=t;l++)
    {
        getline(cin,a);
        printf("Case %d: ",l);
        for(i=0;i<a.size();i++)
        {
            if(a[i]>='A' && a[i]<='Z')
            {
                char p=a[i];
                m=0;
                for(j=i+1;;j++)
                {
                    if(a[j]>='A' && a[j]<='Z')
                    {
                        break;
                    }
                    else
                    {
                        m=m*10+a[j]-'0';
                    }
                    if(j==a.size()-1)
                    {
                        break;
                    }
                }
                for(j=0;j<m;j++)
                {
                    printf("%c",p);
                }
            }
        }
        printf("\n");
    }
}
