#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,sum=0,pos=0,neg=0;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]>=0) pos++;
            else neg++;
            sum+=abs(a[i]);
        }
        if(pos==0){
            cout<<"Case "<<++tc<<": "<<"inf"<<endl;
        }
        else{
            int x=(n-neg);
            int y=__gcd(x,sum);
            cout<<"Case "<<++tc<<": "<<(sum/y)<<"/"<<(x/y)<<endl;
        }
    }
}
