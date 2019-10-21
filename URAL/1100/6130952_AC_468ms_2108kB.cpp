#include <bits/stdc++.h>
using namespace std;
struct team{
    int id;
    int solve;
};
bool comp(team a , team b){
   return (a.solve > b.solve);
}
int main()
{
    team data[150010];
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&data[i].id,&data[i].solve);
    }
    stable_sort(data,data+t,comp);
    for(i=0;i<t;i++)
    {
       printf("%d %d\n",data[i].id,data[i].solve);
    }
}
