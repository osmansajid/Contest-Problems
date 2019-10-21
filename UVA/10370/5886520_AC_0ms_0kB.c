#include <stdio.h>
int main()
{
int t,i,j,x,m;
double l,p;
scanf("%d",&t);
for(i=1;i<=t;i++)
 { double k=0,count=0;
  scanf("%d",&m);
  int a[m];
  for(j=0;j<m;j++)
  {
      scanf("%d",&x);
      a[j]=x;
  }
  for(j=0;j<m;j++)
  {
      k=k+a[j];
  }
  l=k/m;
  for(j=0;j<m;j++)
  {
      if(a[j]>l)
      {
          count++;
      }
  }
  p=count*100/m;
  printf("%.3lf%%\n",p);
  }
  return 0;
 }