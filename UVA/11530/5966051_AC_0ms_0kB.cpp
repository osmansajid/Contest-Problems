#include <stdio.h>
#include <string.h>
int main()
{
    int t,i,j,s,p;
    char x[1000];
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    { s=0;
      gets(x);
      p=strlen(x);
      for(j=0;j<=p;j++)
      {
          if((x[j]=='a') || (x[j]=='d') || (x[j]=='g') || (x[j]=='j') || (x[j]=='m') || (x[j]=='p') || (x[j]=='t') || (x[j]=='w') || (x[j]==' '))
          {
              s=s+1;
          }
          else if((x[j]=='b') || (x[j]=='e') || (x[j]=='h') || (x[j]=='k') || (x[j]=='n') || (x[j]=='q') || (x[j]=='u') || (x[j]=='x'))
          {
              s=s+2;
          }
          else if((x[j]=='c') || (x[j]=='f') || (x[j]=='i') || (x[j]=='l') || (x[j]=='o') || (x[j]=='r') || (x[j]=='v') || (x[j]=='y'))
          {
              s=s+3;
          }
          else if((x[j]=='s') || (x[j]=='z'))
          {
              s=s+4;
          }

      }
     printf("Case #%d: %d\n",i,s);
    }
}
