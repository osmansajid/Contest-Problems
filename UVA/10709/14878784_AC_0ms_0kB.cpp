#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-16
#define NEX(x) ((x+1)%n)
#define PRV(x) ((x-1+n)%n)
#define RAD(x) ((x*M_PI)/180)
#define DEG(x) ((x*180)/M_PI)
#define double long double
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

ostream &operator<<(ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}

istream &operator>>(istream &is, PT &p) {
    is >> p.x >> p.y;
    return is;
}

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

double DistancePointLine(PT a,PT b,PT c) {
    return dist(c,ProjectPointLine(a,b,c));
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
    double r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
    return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
bool LinesParallel(PT a, PT b, PT c, PT d) {
    return dcmp(cross(b-a, c-d)) == 0;
}

bool LinesCollinear(PT a, PT b, PT c, PT d) {
    return LinesParallel(a, b, c, d)
      && dcmp(cross(a-b, a-c)) == 0
      && dcmp(cross(c-d, c-a)) == 0;
}

bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
    if (LinesCollinear(a, b, c, d)) {
        if (dcmp(dist2(a, c)) == 0 || dcmp(dist2(a, d)) == 0 ||
            dcmp(dist2(b, c)) == 0 || dcmp(dist2(b, d)) == 0) return true;
        if (dcmp(dot(c-a, c-b)) > 0 && dcmp(dot(d-a, d-b)) > 0 && dcmp(dot(c-b, d-b)) > 0)
            return false;
        return true;
    }
    if (dcmp(cross(d-a, b-a)) * dcmp(cross(c-a, b-a)) > 0) return false;
    if (dcmp(cross(a-c, d-c)) * dcmp(cross(b-c, d-c)) > 0) return false;
    return true;
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

int main()
{
    //freopen("out.txt","w",stdout);
    double x1,x2,x3,x4,y1,y2,y3,y4;
    string s1,s2;
    while(1){
        double ans;
        cin>>x1>>y1>>x2>>y2>>s1>>x3>>y3>>x4>>y4>>s2;
        PT a(x1,y1),b(x2,y2),c(x3,y3),d(x4,y4);
        if(s1=="END" && s2=="END") break;
        else if(s1=="L" && s2=="L"){
            if(!LinesParallel(a,b,c,d)){
                ans=0;
            }
            else{
                ans=min(min(DistancePointLine(a,b,c),DistancePointLine(a,b,d)),min(DistancePointLine(c,d,a),DistancePointLine(c,d,b)));
            }
        }
        else if(s1=="L" && s2=="LS"){
            if(!LinesParallel(a,b,c,d)){
                //cout<<PointOnSegment(c,d,ComputeLineIntersection(a,b,c,d))<<endl;
                if(PointOnSegment(c,d,ComputeLineIntersection(a,b,c,d))) ans=0.0;
                else ans=min(DistancePointLine(a,b,c),DistancePointLine(a,b,d));
            }
            else ans=min(DistancePointLine(a,b,c),DistancePointLine(a,b,d));
        }
        else if(s1=="LS" && s2=="L"){
            if(!LinesParallel(a,b,c,d)){
                if(PointOnSegment(a,b,ComputeLineIntersection(a,b,c,d))) ans=0.0;
                else ans=min(DistancePointLine(c,d,a),DistancePointLine(c,d,b));
            }
            else ans=min(DistancePointLine(c,d,a),DistancePointLine(c,d,b));
        }
        else{
            if(SegmentsIntersect(a,b,c,d)) ans=0.0;
            else ans=min(min(DistancePointSegment(a,b,c),DistancePointSegment(a,b,d)),min(DistancePointSegment(c,d,a),DistancePointSegment(c,d,b)));
        }
        cout<<setprecision(5)<<fixed;
        cout<<ans<<endl;
    }
}

