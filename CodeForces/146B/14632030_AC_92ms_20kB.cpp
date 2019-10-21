#include<bits/stdc++.h>
using namespace std;
int lucky(int x){
    int ret=0;
    vector<int> s;
    while(x!=0){
        int z=x%10;
        x/=10;
        if(z==7 || z==4){
            s.push_back(z);
        }
    }
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        ret=ret*10+s[i];
    }
    return ret;
}
int main()
{
    int a,b;
    cin>>a>>b;
    if(a<b) cout<<b<<endl;
    else{
        for(int i=a+1;;i++){
            int x=lucky(i);
            if(x==b){
                cout<<i<<endl;
                break;
            }
        }
    }
}