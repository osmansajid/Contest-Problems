#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c,d,ans;
    cin>>a>>b>>c>>d;
    ans=(a/b)/(1-(1-c/d)*(1-(a/b )));
    printf("%.12lf\n",ans);
}
