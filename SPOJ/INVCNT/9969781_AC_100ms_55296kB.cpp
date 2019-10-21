#include<bits/stdc++.h>
using namespace std;
#define mx 10000001
int tree[mx];

//returns cum sum->
int sum(int indx)
{
    int sum = 0;
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
    int t;
    scanf("%d",&t);
    while(t--){
        memset(tree,0,sizeof tree);
        int n;
        scanf("%d",&n);
        int a[n+1];
        long long ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=n-1;i>=0;i--){
            ans+=sum(a[i]-1);
            update(a[i],mx,1);
        }
        printf("%lld\n",ans);
    }
}
