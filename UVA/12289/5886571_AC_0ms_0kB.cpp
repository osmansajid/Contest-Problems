#include <stdio.h>
#include <string.h>
int main()
{
 char a[]="one";
 char b[]="two";
 char c[]="three";
 char d[5];
 int t,i;
 scanf("%d",&t);
 for(i=0;i<=t;i++)
 {
 gets(d);
 if(strlen(d)==3)
 {
  if(d[0]==a[0]&&d[1]==a[1] || d[0]==a[0]&&d[2]==a[2] || d[1]==a[1]&&d[2]==a[2])
  {
   printf("1\n");
  }
  else
  {
   printf("2\n");
  }
 }
 else if(strlen(d)==5)
 {
 printf("3\n");
 }
 }
 return 0;
}
