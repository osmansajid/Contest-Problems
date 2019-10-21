#include<bits/stdc++.h>
using namespace std;

long long tree[1000100];
long long n;
//returns cum sum->
long long sum(int indx)
{
    long long sum = 0;
    while (indx){
        sum += tree[indx];
        indx -= indx & -indx;
    }
    return sum;
}
//updates->
void update(int indx,int n, int val)
{
    while (indx <= n){
        tree[indx] += val;
        indx += indx & (-indx);
    }
}

int main()
{
    int q;
    scanf("%lld %d",&n,&q);
    long long a[n+10],tr[n+10];
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<q;i++){
        int b,e;
        scanf("%d %d",&b,&e);
        update(b,n,1);
        update(e+1,n,-1);
    }
    for(int i=1;i<=n;i++){
        tr[i]=sum(i);
    }
    sort(tr+1,tr+n+1);
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=n;i>=1;i--){
        //cout<<tr[i]<<" "<<a[i+1]<<endl;
        ans+=(tr[i]*a[i]);
    }
    printf("%lld\n",ans);
}
