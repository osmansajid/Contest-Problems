#include<bits/stdc++.h>
using namespace std ;
struct item{
    int  ji,fi;
    double ri;
};

bool operator<(item A,item B){
    return A.ri>B.ri;
}

int main()
{
    int m,n;
    while(cin>>m>>n){
        if(m==-1 && n==-1) break;
        item a[n];
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            a[i].ji=x;
            a[i].fi=y;
            a[i].ri=(double)x/(double)y;
        }
        sort(a,a+n);
        int cur=m;
        double ans=0;
        for(int i=0;i<n;i++){
            //cout<<a[i].ji<<" "<<a[i].fi<<" "<<a[i].ri<<endl;
            if(a[i].fi<=cur){
                ans+=(double)a[i].ji;
                cur-=a[i].fi;
            }
            else{
                ans+=((double)a[i].ri*(double)cur);
                cur=0;
            }
            if(cur==0)break;
        }
        printf("%.3lf\n",ans);
    }
}
