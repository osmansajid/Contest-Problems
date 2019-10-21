#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string v,ans="";
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        v+=x;
        if(i!=n-1)v+=" ";
    }
    //cout<<v<<endl;
    int m;
    cin>>m;
    int f=0;
    string tmp;
    for(int i=0;i<m;i++){
        string x;
        cin>>x;
        if(x=="CapsLock"){
            if(f==1)f=0;
            else f=1;
        }
        else if(x=="Space"){
           ans+=" ";
        }
        else if(x=="Backspace"){
            if(ans.size()!=0)ans.pop_back();
        }
        else{
            char tt=x[0];
            if(f==1) tt=tt-32;
            ans.push_back(tt);
        }
    }
//ans+=tmp;
    //cout<<ans.size()<<" "<<v.size()<<endl;

    if(ans!=v) cout<<"Incorrect"<<endl;
    else cout<<"Correct"<<endl;
}


