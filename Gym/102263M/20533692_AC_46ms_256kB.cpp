#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    char cur=s[s.size()-1];
    string tmp,ans;
    int f=0;
    while(s.size()>1){
        if(f==1) break;
        int i=s.size()-1;
        //if(s[i]=='z')break;
        if(cur!=s[i]){
            s+=tmp;
            tmp.clear();
            cur=s[s.size()-1];
            continue;
        }
        if(s[i]==s[i-1]){
            if(s[i]=='z'){
                f=1;
                continue;
            }
            char nxt=s[i]+1;
            tmp.push_back(nxt);
            s.pop_back();
            s.pop_back();
            if(s.size()<=1){
                s+=tmp;
                tmp.clear();
            }
        }
        else{
            ans.push_back(s[i]);
            s.pop_back();
            s+=tmp;
            tmp.clear();
        }
    }
    ans+=s;
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
