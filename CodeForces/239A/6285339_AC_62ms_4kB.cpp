#include<bits/stdc++.h>
using namespace std;
int main()
{
    int y, k, n,x ,m;
    scanf("%d %d %d", &y, &k, &n);
    x = k - y % k;
    m = n - y;
    if (x <= m)
    {
        printf("%d", x);
        x =x+ k;
        while (x <= m)
        {
            printf(" %d", x);
            x =x+ k;
        }
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }
}
