#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long r,c;
    while(cin>>r>>c){
        if(r==0 && c==0) break;
        else{
            long long ans=(c*(c-1)*r)+(r*(r-1)*c);
            long long ans1=0;
            long long res=((r-1)+(c-2));
            long long val=2,mval=min(r,c);
            for(long long i=1;i<=res/2;i++){
                ans1+=2*(val*(val-1));
                if(val!=mval)val++;
            }
            if(res%2!=0) ans1+=(mval*(mval-1));
            cout<<ans+(2*ans1)<<endl;
        }
    }
}
