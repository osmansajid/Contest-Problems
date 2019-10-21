#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > v,ans,ok;
    for(int i=0;i<n/2;i++){
        int x,y;
        cin>>x>>y;
        if(y<x)swap(x,y);
        v.push_back(make_pair(x,y));
    }
    map<int,int>mark;
    sort(v.begin(),v.end());
    ans.push_back(v[0]);
    mark[0]=1;
    for(int i=1;i<n/2;i++){
        if(v[i].first>=ans[(int)ans.size()-1].second){
            mark[i]=1;
            ans.push_back(v[i]);
        }
    }
    int tmp=(int)ans.size()-1,flg=0;
    for(int i=0;i<n/2;i++){
        if(mark[i]==0){
              ok.push_back(make_pair(v[i].second,v[i].first));
        }
    }
    sort(ok.begin(),ok.end());
    reverse(ok.begin(),ok.end());
   if(ok.size()!=0)ans.push_back(ok[0]);
    for(int i=1;i<ok.size();i++){
        if(ok[i].first<=ans[tmp].second){
            ans.push_back(make_pair(ok[i].first,ok[i].second));
            tmp++;
        }
        else{
            flg=1;
        }
    }
    if(flg)cout<<-1<<endl;
    else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<" ";
        }
        cout<<endl;
    }
}
