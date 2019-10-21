#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
int test;
double l,r,a,w;
scanf("%d", &test);
while(test--)
    {
     scanf("%lf", &l);
     w = (6*l)/10.00;
     r = (2*l)/10.00;
     a = acos(-1.00)*r*r;
     printf("%.2lf %.2lf\n", a,(l*w - a));
    }
 return 0;
}
