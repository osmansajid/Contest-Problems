#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,n,m,x,y,i;
    while(scanf("%d",&k)==1)
    {
        if(k==0)
        {
            break;
        }
        else
        {
            scanf("%d %d",&n,&m);

        for(i=1;i<=k;i++)
        {
             scanf("%d %d",&x,&y);
             x=x-n;
            y=y-m;
            if(x>0 && y>0)
            {
                printf("NE\n");
            }
            else if(x>0 && y<0)
            {
                printf("SE\n");
            }
            else if(x<0 &&y<0)
            {
                printf("SO\n");
            }
            else if(x<0 && y>0)
            {
                printf("NO\n");
            }
            else if(x==0 || y==0)
            {
                printf("divisa\n");
            }
          }
      }


    }
}
