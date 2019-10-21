#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int>mp;
    map<int,string>mp2;
    mp["063"]=0;
    mp["010"]=1;
    mp["093"]=2;
    mp["079"]=3;
    mp["106"]=4;
    mp["103"]=5;
    mp["119"]=6;
    mp["011"]=7;
    mp["127"]=8;
    mp["107"]=9;

    mp2[0]="063";
    mp2[1]="010";
    mp2[2]="093";
    mp2[3]="079";
    mp2[4]="106";
    mp2[5]="103";
    mp2[6]="119";
    mp2[7]="011";
    mp2[8]="127";
    mp2[9]="107";
    while(1){
        string s;
        cin>>s;
        int ans1=0,ans2=0,f=0,cnt=0;
        if(s=="BYE") break;
        else{
            string tmp;
            for(int i=0;i<s.size();i++){
                if(cnt%3==0 && cnt!=0){
                    if(f){
                        ans2=(ans2*10)+(mp[tmp]);
                    }
                    else{
                        ans1=(ans1*10)+(mp[tmp]);
                        //cout<<ans1<<endl;
                    }
                    tmp.clear();
                    if(s[i]=='+'){
                        f=1;
                        continue;
                    }
                    if(i==s.size()-1) continue;
                }
                tmp.push_back(s[i]);
                cnt++;
                //cout<<tmp<<endl;
            }
            ans1=ans1+ans2;
            vector<string> ans;
            while(ans1){
                int x=ans1%10;
                ans1/=10;
                ans.push_back(mp2[x]);
            }
            reverse(ans.begin(),ans.end());
            cout<<s;
            for(int i=0;i<ans.size();i++){
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
}
