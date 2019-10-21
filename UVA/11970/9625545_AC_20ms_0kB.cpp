#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        int n,j=0;
        vector<int>a;
        cin>>n;
        for(int i=1;;i++){
            if(i*i>=n) break;
            double ans=n-(i*i);
            double ans2=(ans)/sqrt(n-ans);
            int ans3=ans/sqrt(n-ans);
            if(ans2==ans3){
                a.push_back(ans);
            }
        }
        sort(a.begin(),a.end());
        cout<<"Case "<<++tc<<":";
        for(int i=0;i<a.size();i++){
            cout<<" "<<a[i];
        }
        cout<<endl;
    }
}
