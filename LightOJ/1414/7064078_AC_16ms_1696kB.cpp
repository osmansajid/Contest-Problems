#include<bits/stdc++.h>
using namespace std;
int leap_year(int n)
{
    if(n%4==0)
    {
        if(n%100==0)
        {
            if(n%400==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}
int main()
{
    string a1,a2,b1,b2;
    int d1,d2,y1,y2,i,t,k,ym,yn,y;
    map<string,int>mp;
    mp["january"]=1;
    mp["February"]=2;
    mp["March"]=3;
    mp["April"]=4;
    mp["May"]=5;
    mp["June"]=6;
    mp["July"]=7;
    mp["August"]=8;
    mp["September"]=9;
    mp["October"]=10;
    mp["November"]=11;
    mp["December"]=12;
    cin>>t;
    for(k=1;k<=t;k++)
    {
      cin>>a1>>d1>>b1>>y1>>a2>>d2>>b2>>y2;
      int count =0,flag=0;
      if(y1!=y2)
      {
              if(leap_year(y1)==1)
              {
                 flag=1;
                 if(mp[a1]<=2)
                 {
                    count++;
                 }
              }

             if(leap_year(y2)==1)
             {
                 if(mp[a2]>2 ||(mp[a2]==2 && d2==29))
                 {
                     count++;
                 }
             }
             ym=((y1)/4)-((y1)/100)+((y1)/400);
             yn=((y2-1)/4)-((y2-1)/100)+((y2-1)/400);
             y=yn-ym;
             if(y>0)
             {
              count+=y;
             }
      }
    else
    {
        if((mp[a1]<=2 && d1<=29 )&& (mp[a2]>2 ||(mp[a2]==2 && d2==29)) && leap_year(y1)==1)
        {
            count++;
        }
    }
      printf("Case %d: %d\n",k,count);
    }
}

