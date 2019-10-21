#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-12
#define NEX(x) ((x+1)%n)
#define PRV(x) ((x-1+n)%n)
#define RAD(x) ((x*M_PI)/180)
#define DEG(x) ((x*180)/M_PI)
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

bool LinesParallel(PT a, PT b, PT c, PT d) {
    return dcmp(cross(b-a, c-d)) == 0;
}

bool PointOnSegment(PT p, PT r, PT q) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b=b-a; d=c-d; c=c-a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}

PT ProjectPointLine(PT a, PT b, PT c) {
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

double DistancePointLine(PT a,PT b,PT c) {
    return dist(c,ProjectPointLine(a,b,c));
}

bool check(PT a,PT d,PT b){
    double dd=((d.x*(a.y-b.y))-(d.y*(a.x-b.x))-((b.x*a.y)-(a.x*b.y)));
    if(dd>0.0) return 1;
    return 0;
}

double ComputeSignedArea(const vector<PT> &p) {
    double area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}

double ComputeArea(const vector<PT> &p) {
    return fabs(ComputeSignedArea(p));
}

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        int n;
        double ax,mini=-1;
        cin>>n>>ax;
        vector<PT> p,ans,prev;
        for(int i=0;i<n;i++){
            double xx,yy;
            cin>>xx>>yy;
            PT pp(xx,yy);
            if(yy>mini){
                mini=yy;
                //cout<<yy<<endl;
                ans.push_back(pp);
                if(p.size())prev.push_back(p[p.size()-1]);
            }
            p.push_back(pp);
        }
        PT a(ax,0),b,c,d;
        b=ans[0];
        double OK=0;
        for(int i=1;i<ans.size();i++){

//            b=ans[i-1];
            c=prev[i-1];
            d=ans[i];
            if(check(a,d,b)){
                PT zz=ComputeLineIntersection(a,b,c,d);
                //cout<<dist(zz,d)<<" "<<zz.x<<" "<<zz.y<<" "<<c.x<<" "<<c.y<<" "<<d.x<<" "<<d.y<<endl;
                OK+=dist(zz,d);
                b=d;
            }
        }
        cout<<setprecision(10)<<fixed;
        cout<<"Case "<<++tc<<": "<<OK<<endl;
    }
}
