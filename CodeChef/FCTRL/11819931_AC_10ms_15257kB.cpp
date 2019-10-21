#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,ans=0;
        scanf("%d",&n);
        while(n!=0){
            ans+=(n/5);
            n=n/5;
        }
        printf("%d\n",ans);
    }
}
