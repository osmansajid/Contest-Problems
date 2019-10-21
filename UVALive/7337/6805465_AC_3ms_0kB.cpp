#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    getchar();
    string a;
    string b;
    queue<string> s;
    s.push("FRI");
    s.push("SAT");
    s.push("SUN");
    s.push("MON");
    s.push("TUE");
    s.push("WED");
    s.push("THU");
    for(j=0;j<n;j++)
    {
         cin>>a;
         map<string,int> mp;
         if(a=="JAN"|| a=="MAR"|| a=="MAY"||a=="JUL"|| a=="AUG"||a=="OCT"||a=="DEC")
         {
             mp[a]=31;
         }
         else if(a=="APR"|| a=="JUN"|| a=="SEP"|| a=="NOV")
         {
             mp[a]=30;
         }
         else if(a=="FEB")
         {
             mp[a]=28;
         }
         cin>>b;
         int count=0;
         for(i=0;i<7;i++)
         {
             if(s.front()==b)
             {
                break;
             }
             else
             {
                 s.push(s.front());
                 s.pop();
             }
         }
         for(i=1;i<=mp[a];i++)
         {
             if(s.front()=="FRI"||s.front()=="SAT")
             {
                 count++;
             }
             s.push(s.front());
             s.pop();
         }
         printf("%d\n",count);

    }
}
