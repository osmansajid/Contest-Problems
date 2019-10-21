#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        int n,m,cnt=0;
        cin>>n>>m;
        getchar();
        map<string,int>mp;
        string a[n],b[m];
        for(int i=0;i<n;i++){
            getline(cin,a[i]);
        }
        for(int i=0;i<m;i++){
            getline(cin,b[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string c=a[i]+b[j];
                if(!mp[c]){
                    mp[c]=1;
                    cnt++;
                }
            }
        }
        cout<<"Case "<<++tc<<": "<<cnt<<endl;
        mp.clear();
    }
}
