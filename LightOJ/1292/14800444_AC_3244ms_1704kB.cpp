#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-12
#define NEX(x) ((x+1)%n)
#define PRV(x) ((x-1+n)%n)
#define RAD(x) ((x*M_PI)/180)
#define DEG(x) ((x*180)/M_PI)
#define double long long
const double PI=acos(-1.0);

inline int dcmp (double x) { return x < -EPS ? -1 : (x > EPS); }
//inline int dcmp (int x) { return (x>0) - (x<0); }

class PT {
public:
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    double Magnitude() {return sqrt(x*x+y*y);}

    bool operator == (const PT& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
    bool operator != (const PT& u) const { return !(*this == u); }
    bool operator < (const PT& u) const { return dcmp(x - u.x) < 0 || (dcmp(x-u.x)==0 && dcmp(y-u.y) < 0); }
    bool operator > (const PT& u) const { return u < *this; }
    bool operator <= (const PT& u) const { return *this < u || *this == u; }
    bool operator >= (const PT& u) const { return *this > u || *this == u; }
    PT operator + (const PT& u) const { return PT(x + u.x, y + u.y); }
    PT operator - (const PT& u) const { return PT(x - u.x, y - u.y); }
    PT operator * (const double u) const { return PT(x * u, y * u); }
    PT operator / (const double u) const { return PT(x / u, y / u); }
    double operator * (const PT& u) const { return x*u.y - y*u.x; }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double dist(PT p, PT q)   { return sqrt(dist2(p,q)); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<PT>pts;
        for(int i=0;i<n;i++){
            PT a;
            long long xx,yy;
            cin>>xx>>yy;
            a.x=xx;
            a.y=yy;
            pts.push_back(a);
        }
        if(n==1) cout<<"Case "<<++tc<<": "<<1<<endl;
        else{
            int ret=0;
            for(int i=0;i<n;i++){
                map<pair<long long,long long>,int> ans;
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    long long val1=(pts[i].y-pts[j].y);
                    long long val2=(pts[i].x-pts[j].x);
                    val1=(val2==0)?1:val1;
                    val2=(val1==0)?1:val2;
                    long long g=__gcd(abs(val1),abs(val2));
                    val1/=g;
                    val2/=g;
                    //cout<<val1<<" "<<val2<<endl;
                    ans[make_pair(val1,val2)]++;
                }
                for(map<pair<long long,long long>,int>::iterator j=ans.begin();j!=ans.end();j++){
                    ret=max(ret,j->second +1);
                }
            }
            cout<<"Case "<<++tc<<": "<<ret<<endl;
        }
    }
}
