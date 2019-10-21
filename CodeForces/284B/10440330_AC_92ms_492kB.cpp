#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a[200];
    memset(a,0,sizeof a);
    for(int i=0;i<n;i++){
        a[s[i]]++;
    }
    if(a['I']>=2){
        cout<<0<<endl;
    }
    else if(a['I']==1){
        cout<<1<<endl;
    }
    else{
        cout<<a['A']<<endl;
    }
}
