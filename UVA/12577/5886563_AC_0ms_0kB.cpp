#include <stdio.h>
#include <string.h>
int main()
 {
  char a[]="Hajj";
  char b[]="Umrah";
  char c[5];
  char n[]="*";
  int t=0;
  while(gets(c))
  { t++;
   if(c[0]!=n[0])
  {
  if(c[0]==a[0])
   {
   printf("Case %d: Hajj-e-Akbar\n",t);
   }
  else
  {
  printf("Case %d: Hajj-e-Asghar\n",t);
  }
  }
  else
  {
      break;
  }
  }
  return 0;
 }


