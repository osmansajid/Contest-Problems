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
            ans+=(n%10);
            n=n/10;
        }
        printf("%d\n",ans);
    }
}
