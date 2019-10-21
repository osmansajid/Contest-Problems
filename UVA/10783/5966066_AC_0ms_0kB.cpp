#include<stdio.h>
int main()
{
 int T,a,b,i,j,s;
 scanf("%d",&T);
 for(i=1;i<=T;i++)
 {scanf("%d %d",&a,&b);
 s=0;
  for(j=a;j<=b; j++)
  { if(j%2!=0)
      {
         s=s+j;
      }
  }
  printf("Case %d: %d\n",i,s);

}
return 0;
}