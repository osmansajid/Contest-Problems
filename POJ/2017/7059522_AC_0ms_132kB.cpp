#include<stdio.h>
int main()
{
    int t;
    while(scanf("%d",&t))
    {
     int s,v,n=0,l=0;
     if(t==-1)
     {
         break;
     }
     else
     {
        while(t--)
        {
        scanf("%d %d",&s,&v);
        n+=s*(v-l);
        l=v;
        }
     }
     printf("%d miles\n",n);
    }
}
