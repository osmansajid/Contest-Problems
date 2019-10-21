#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,cnt=0;
    char c;
    string v;
    vector<char>s;
    map<char,int>mp;
    while(cin>>t){
        if(t==-1)break;
        cin>>c>>v;
        if(v=="right"){
            mp[c]+=t;
            s.push_back(c);
        }
        else{
            mp[c]+=(20);
        }
    }
    for(int i=0;i<s.size();i++){
        cnt+=mp[s[i]];
    }
    cout<<s.size()<<" "<<cnt<<endl;
}
