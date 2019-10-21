#include<bits/stdc++.h>
using namespace std;
int n,a[20];

void gen(vector<int> &s,int indx,int last,int val){
    s.push_back(val);
    if(indx==last) return;
    gen(s,indx+1,last,val);
    gen(s,indx+1,last,val+a[indx]);
    gen(s,indx+1,last,val+2*a[indx]);
}

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        int m,found=0;
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> set1,set2;
        gen(set1,0,n/2,0);
        gen(set2,n/2,n,0);
        sort(set1.begin(),set1.end());
        for(int i=0;i<set2.size();i++){
            if(binary_search(set1.begin(),set1.end(),m-set2[i])){
                found=1;
                break;
            }
        }
        if(found==1) cout<<"Case "<<++tc<<": Yes"<<endl;
        else cout<<"Case "<<++tc<<": No"<<endl;
    }
}
