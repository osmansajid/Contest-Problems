#include <stdio.h>
int main()
{
 int t,i;
 int a[10];
 scanf("%d",&t);
 printf("Lumberjacks:\n");
 for(i=1;i<=t;i++)
 { scanf("%d %d %d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
  if((a[0]>a[1] &&a[1]>a[2] &&a[2]>a[3] &&a[3]>a[4] &&a[4]>a[5] &&a[5]>a[6] &&a[6]>a[7] &&a[7]>a[8] &&a[8]>a[9]) || (a[9]>a[8] &&a[8]>a[7] &&a[7]>a[6] &&a[6]>a[5] &&a[5]>a[4] &&a[4]>a[3] &&a[3]>a[2] &&a[2]>a[1] &&a[1]>a[0]))
  {
   printf("Ordered\n");
  }
  else
  {
   printf("Unordered\n");
  }
 }
 return 0;
}