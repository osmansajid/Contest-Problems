#include<bits/stdc++.h>
using namespace std;
long long Pow(long long x,long long y){
   if(y==0) return 1;
   else if(y%2==0){
        long long a=Pow(x,y/2);
        return a*a;
   }
   else return x*Pow(x,y-1);
}

bool check(int x,int n,int k){
    int ans=0;
    for(int y=1;x/y>0;y=y*k){
        ans+=x/y;
    }
    if(ans>=n)return true;
    return false;
}
int main()
{
    long long n,k;
    cin>>n>>k;
    long long low=0,high=n,i;
    while(low<high){
        i=(low+high)/2;
        if(check(i,n,k)){
            high=i;
        }
        else{
            low=i+1;
        }
    }
    cout<<low<<endl;

}
