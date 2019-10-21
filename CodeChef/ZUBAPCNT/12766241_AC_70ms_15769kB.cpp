#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long Pow(long long x,long long y){
   if(y==0) return 1;
   else if(y%2==0){
        long long a=Pow(x,y/2)%MOD;
        return ((a%MOD)*(a%MOD))%MOD;
   }
   else return ((x%MOD)*(Pow(x,y-1)%MOD))%MOD;
}


int main()
{
    ios_base::sync_with_stdio(0);  cin.tie(0);
    int t,tc=0;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<"Case "<<++tc<<":"<<endl;
        for(int i=0;i<m;i++){
            string s;
            cin>>s;
            if(s.size()==n){
                cout<<1<<endl;
            }
            else if(s.size()>n){
                cout<<0<<endl;
            }
            else{
                long long first,second=1,x=(n-s.size())+1;
                first=x%MOD;
                second=Pow(26,x-1)%MOD;
                first=((first%MOD)*(second%MOD))%MOD;
                cout<<first<<endl;
            }
        }
    }
}
