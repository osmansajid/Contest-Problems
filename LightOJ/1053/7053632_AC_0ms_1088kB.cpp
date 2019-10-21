#include <stdio.h>
int main()
{
    int i,a,b,c,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a>=b && a>=c)
        {
            if(a*a==b*b+c*c)
            {
                printf("Case %d: yes\n",i);
            }
            else
            {
                printf("Case %d: no\n",i);
            }
        }
        else if(c>=a && c>=b)
        {
            if(c*c==b*b+a*a)
            {
                printf("Case %d: yes\n",i);
            }
            else
            {
                printf("Case %d: no\n",i);
            }
        }
        else if(b>=a && b>=c)
        {
            if(b*b==c*c+a*a)
            {
                printf("Case %d: yes\n",i);
            }
            else
            {
                printf("Case %d: no\n",i);
            }
        }
    }
}
