#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int>mp;
    mp["Hajj"]=1;
    string a;
    long long i=0;
    while(getline(cin,a))
    {
        i++;
        if(a=="*")
        {
            break;
        }
        if(mp.find(a)!= mp.end())
       {
        cout<<"Case"<<" "<<i<<":"<<" "<<"Hajj-e-Akbar"<<endl;
       }
        else
       {
        cout<<"Case"<<" "<<i<<":"<<" "<<"Hajj-e-Asghar"<<endl;
       }
    }

}
