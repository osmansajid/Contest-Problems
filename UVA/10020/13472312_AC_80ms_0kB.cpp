#include<bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
};

bool operator<(point a,point b){
    if(a.x==b.x) a.y>b.y;
    return a.x<b.x;
}
int main()
{
    bool ok=false;
    //freopen("in.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        bool ans=true,add=true;
        int n,a,b,sz=0;
        cin>>n;
        point p[100005];
        while(cin>>a>>b){
            if(a==0 && b==0) break;
            p[sz].x=a;
            p[sz].y=b;
            sz++;
        }
        sort(p,p+sz);
        vector<point>v;
        point next;
        int last=0,nlast=0,cnt=0;
        for(int i=0;i<sz;){
            if(p[i].x<=last && p[i].y>last){
                if(nlast<p[i].y){
                    nlast=p[i].y;
                    next.x=p[i].x;
                    next.y=p[i].y;
                }
                i++;
            }
            else if(p[i].x>last){
                last=nlast;
                if(last>=n){
                    v.push_back(next);
                    add=false;
                    break;
                }
                if(p[i].x>last){
                    ans=false;
                    break;
                }
                v.push_back(next);
            }
            else if(p[i].y<=last){
                i++;
            }
        }
        if(add==true && next.y>=n) v.push_back(next);
        else if(add==true && next.y<n) ans=false;
        if(ok)cout<<endl;
        if(ans){
            cout<<v.size()<<endl;
            for(int i=0;i<v.size();i++){
                cout<<v[i].x<<" "<<v[i].y<<endl;
            }
            //cout<<endl;
        }
        else cout<<0<<endl;
        ok=true;
    }
}
