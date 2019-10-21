#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,s,p;
    string x;
    cin>>t;
    getchar();
    for(i=1;i<=t;i++)
    { s=0;
      getline(cin,x);
      map<char,int>mp;
      for(j=0;j<=x.size();j++)
      {
          if((x[j]=='a') || (x[j]=='d') || (x[j]=='g') || (x[j]=='j') || (x[j]=='m') || (x[j]=='p') || (x[j]=='t') || (x[j]=='w') || (x[j]==' '))
          {
              mp[x[j]]=1;
          }
          else if((x[j]=='b') || (x[j]=='e') || (x[j]=='h') || (x[j]=='k') || (x[j]=='n') || (x[j]=='q') || (x[j]=='u') || (x[j]=='x'))
          {
              mp[x[j]]=2;
          }
          else if((x[j]=='c') || (x[j]=='f') || (x[j]=='i') || (x[j]=='l') || (x[j]=='o') || (x[j]=='r') || (x[j]=='v') || (x[j]=='y'))
          {
              mp[x[j]]=3;
          }
          else if((x[j]=='s') || (x[j]=='z'))
          {
              mp[x[j]]=4;
          }

      }
      for(j=0;j<x.size();j++)
      {
          if(mp[x[j]])
          {
              s=s+mp[x[j]];
          }
      }
     printf("Case #%d: %d\n",i,s);
    }
}

