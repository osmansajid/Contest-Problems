#include<bits/stdc++.h>
using namespace std;

double call(double n,double in){
    if(in==n)return 0;
    double res=0.0;
    res+=(n*((double)(in/n)+(double)((n-in)/n)*call(n,in+1)))/(double)(n-in);
    return res+1.0;
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        double n;
        scanf("%lf",&n);
        printf("Case %d: %.10lf\n",++tc,call(n,1.0)+1);
    }
}
