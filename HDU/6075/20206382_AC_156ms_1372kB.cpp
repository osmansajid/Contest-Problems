#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,ev=0,od=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            if(x%2==0){
                ev++;
            }
            else{
                od++;
            }
        }
        if(ev>od){
            printf("2 0\n");
        }
        else{
            printf("2 1\n");
        }
    }
}
