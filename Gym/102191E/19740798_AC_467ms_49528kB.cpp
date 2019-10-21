#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mx=INT_MIN,tmp=0,x=0,y=0,prv=0;
    map<pair<int,int>,int>mp;
    vector<pair<int,int> > pos;
    pos.push_back(make_pair(0,0));
    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            x++;
            pos.push_back(make_pair(x,y));
        }
        else if(s[i]=='L'){
            x--;
            pos.push_back(make_pair(x,y));
        }
        else if(s[i]=='U'){
            y++;
            pos.push_back(make_pair(x,y));
        }
        else {
            y--;
            pos.push_back(make_pair(x,y));
        }
       // cout<<tmp<<endl;
    }
  // cout<<pos.size()<<endl;
   // prv=0;
    for(int i=0;i<pos.size();i++){
       // cout<<pos[i].first<<" "<<pos[i].second<<" "<<prv<<endl;
        if(mp[pos[i]]!=0){
            while(mp[pos[i]] && prv<i){
                mp.erase(pos[prv]);
                //cout<<i<<" "<<prv<<" "<<pos[prv].first<<" "<<pos[prv].second<<endl;
                prv++;
            }
            mx=max(mx,i-prv);
            mp[pos[i]]=1;
            //cout<<i-prv<<endl;
            //cout<<prv<<endl;
        }
        else{
            mx=max(mx,i-prv);
            mp[pos[i]]=1;
            //cout<<i-prv+1<<endl;
        }
    }
    cout<<mx<<endl;
}
