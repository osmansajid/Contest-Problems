#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int tree[100010];
struct sub{
    int val;
    int id;
};

bool operator<(sub a,sub b){
    if(a.val==b.val){
        return a.id<b.id;
    }
    return a.val<b.val;
}
//returns cum sum->
int sum(int indx)
{
    int sum = 0;
    while (indx){
        sum = (sum%mod+tree[indx]%mod)%mod;
        indx -= indx & -indx;
    }
    return sum%mod;
}
//updates->
void update(int indx,int n, int val)
{
    while (indx <= n){
        tree[indx] = ((tree[indx])%mod+val%mod)%mod;
        indx += indx & (-indx);
    }
}


int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        memset(tree,0,sizeof tree);
        int n,x;
        scanf("%d",&n);
        sub a[n];
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            a[i].id=i;
            a[i].val=x;
        }
        sort(a,a+n);
        long long prev=0,ans=0;
        prev=1+sum(a[0].id);
        update(a[0].id+1,n,prev);
        for(int i=1;i<n;i++){
            //cout<<a[i].val<<" "<<a[i].id<<endl;
            if(a[i].val!=a[i-1].val){
                ans=1+sum(a[i].id);
                update(a[i].id+1,n,ans);
                prev=ans;
            }
            else{
                ans=1+sum(a[i].id)-prev;
                update(a[i].id+1,n,ans);
                prev+=ans;
            }
        }
        printf("Case %d: %d\n",++tc,sum(n));
    }
}
