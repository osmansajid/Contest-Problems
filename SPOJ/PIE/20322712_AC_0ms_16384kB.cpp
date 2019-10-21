#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
vector<double> v;

bool chck(double mid,int f){
    int cnt=0;
    for(int i=0;i<v.size();i++){
        int x=v[i]/mid;
        cnt+=x;
    }
    if(cnt>=f) return true;
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,f;
        scanf("%d %d",&n,&f);
        f++;
        v.clear();
        double lo=0.0,hi=0.0;
        for(int i=0;i<n;i++){
            double x;
            scanf("%lf",&x);
            v.push_back(PI*x*x);
            hi=max(hi,v[i]);
        }
        while(hi-lo>0.0001){
            double mid=(lo+hi)/2.0;
            if(chck(mid,f)){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
        printf("%.4lf\n",lo);
    }
}
