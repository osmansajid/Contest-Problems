#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        double a,b,c,R;
        cin>>a>>b>>c>>R;
        double low=0,high=a,mid,y,z,p,r,s,q,a1,a2;
        while(high-low>0.0000000001){
            mid=(low+high)/2;
            y=b*(mid/a);
            z=c*(mid/a);
            r=a-mid;
            s=b-y;
            p=mid+y+z;
            q=a+b+c;
            a1=sqrt(p*(p-mid)*(p-y)*(p-z));
            a2=(sqrt(q*(q-a)*(q-b)*(q-c))-a1);
            if(a1/a2>R){
                high=mid;
            }
            else{
                low=mid;
            }
        }
        printf("Case %d: %.10lf\n",++tc,mid);
    }
}
