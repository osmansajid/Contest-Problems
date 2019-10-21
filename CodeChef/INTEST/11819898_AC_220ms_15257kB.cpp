#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,cnt=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x%k==0) cnt++;
    }
    cout<<cnt<<endl;
}
