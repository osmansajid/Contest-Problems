#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,m;
        printf("Case %d:\n",++tc);
        scanf("%d %d",&n,&m);
        string s,a;
        for(int i=0;i<n;i++){
            s.push_back('A'+i);
        }
        cout<<s<<endl;
        a=s;
        for(int i=1;i<m;i++){
            next_permutation(s.begin(),s.end());
            if(s!=a)cout<<s<<endl;
            else break;
        }
    }
}
