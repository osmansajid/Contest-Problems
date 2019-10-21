#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("out.txt","w",stdout);
    double p,q,r,s,t,u;
    while(cin>>p>>q>>r>>s>>t>>u){
        int cnt=500;
        double lo=0,hi=1,mid,ans;
        while(cnt){
            mid=(lo+hi)/2.0;
            ans=(p*exp(-mid))+(q*sin(mid))+(r*cos(mid))+(s*tan(mid))+t*mid*mid+u;
            //cout<<ans<<endl;
            if(ans>0.0) lo=mid;
            else hi=mid;
            cnt--;
        }
        ans=((p*exp(-1.0))+(q*sin(1.0))+(r*cos(1.0))+(s*tan(1.0))+t*1.0*1.0+u)*((p*exp(-0.0))+(q*sin(0.0))+(r*cos(0.0))+(s*tan(0.0))+t*0.0*0.0+u);
        if(ans>0.0)cout<<"No solution"<<endl;
        else{
            printf("%.4lf\n",mid);
        }
    }
}
