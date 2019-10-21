#include<bits/stdc++.h>
using namespace std;

pair<int,int> make_int(string s,int j){
    int x=0,i;
    for(i=j;i<s.size();i++){
        if(s[i]==' ') break;
        x=x*10+(s[i]-'0');
    }
    return make_pair(x,i);
}
int main()
{
    int n;
    cin>>n;
    getchar();
    string s;
    getline(cin,s);
    int counter=1,f=0;
    for(int i=0;i<s.size();){
        if(s[i]=='m'){
            counter++;
            i+=7;
        }
        else{
            pair<int,int>ans=make_int(s,i);
            //cout<<ans.first<<endl;
            if(ans.first!=counter){
                f=1;
                break;
            }
            else{
                i=ans.second+1;
                counter++;
            }
        }
    }
    if(f==0) cout<<"makes sense"<<endl;
    else cout<<"something is fishy"<<endl;
}
