#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    float r,count;
    cin>>n;
    getchar();
    getchar();
    while(n--)
    {
        map<string,float>mp;
        vector<string>v;
        string a;
        count=0;
        while(getline(cin,a))
        {
            if(a.size()==0)
            {
                break;
            }
            if(mp.find(a)==mp.end())
            {
             v.push_back(a);
            }
            mp[a]++;
            count++;
        }
        sort(v.begin(),v.end());

        for(i=0;i<v.size();i++)
        {
            r=(mp[v[i]]/count)*100;
            printf("%s %.4f\n",v[i].c_str(),r);
        }
      if(n>0)
      {
          printf("\n");
      }
    }
}
