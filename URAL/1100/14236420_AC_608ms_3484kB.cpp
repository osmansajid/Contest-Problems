#include<bits/stdc++.h>
using namespace std;
struct myst{
    int a,b,c;
};
bool operator<(myst A,myst B)
{
    if(A.b>B.b) return true;
    else if(A.b==B.b){
        return A.c<B.c;
    }
    else return false;
}

int main()
{
    int n;
    cin>>n;
    vector<myst> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        myst x;
        x.a=a;
        x.b=b;
        x.c=i;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i].a<<" "<<v[i].b<<endl;
    }
}
