#include <stdio.h>
#include<math.h>
int main()
{
    double N,n,i;
    for(i=1;;i++)
    {
        scanf("%lf",&N);
        if(N==0)
        {
            break;
        }
        n=ceil((3+sqrt(9+N*8))/2);
        printf("Case %.0lf: %.0lf\n",i,n);

    }

}
