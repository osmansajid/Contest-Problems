#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> st,en;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            st.push_back(a);
            en.push_back(b);
        }
        sort(st.begin(),st.end());
        sort(en.begin(),en.end());
        int j=0,cnt=0,ans=-1;
        for(int i=0;i<n;i++){
            if(st[i]<en[j]) cnt++;
            else if(st[i]==en[j]){
                j++;
            }
            else{
                j++;
                i--;
                cnt--;
            }
            //cout<<cnt<<endl;
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
}
