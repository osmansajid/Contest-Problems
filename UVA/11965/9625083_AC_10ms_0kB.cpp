#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        if(tc) cout<<endl;
        int n;
        cin>>n;
        getchar();
        string t[n+2];
        for(int i=0;i<n;i++){
            string s;
            getline(cin,s);
            t[i].push_back(s[0]);
            for(int j=1;j<s.size();j++){
                if(s[j-1]==' ' && s[j]==' '){
                    continue;
                }
                else{
                    t[i].push_back(s[j]);
                }
            }
        }
        cout<<"Case "<<++tc<<":"<<endl;
        for(int i=0;i<n;i++){
            cout<<t[i]<<endl;
        }
    }
}
