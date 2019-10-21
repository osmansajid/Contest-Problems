#include<bits/stdc++.h>
using namespace std;
#define mx 200010
long long arr[mx];

//info is a structure to store the sums and update values(prop)
struct info{
    long long sum;
    long long val;
    long long prop;
}tree[mx * 4];//3* of array size

//creates the tree
void init(int node,int b,int e){
    if(b==e){
        tree[node].sum=b;
        tree[node].val=arr[b];
        tree[node].prop=0;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].prop=0;
}

//gives ans to the cum sum in a given range of i to j... carry passes the updated value
long long query(int node,int b,int e,int i,int j,long long carry=0){
    if(e<i || b>j){
        return 0;
    }
    if(b>=i && e<=j){
        return (tree[node].sum+ carry*(e-b+1));
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    long long res1=query(left,b,mid,i,j,carry+tree[node].prop);
    long long res2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return res1+res2;
}

void update(int node,int b,int e,int i,int j,long long newVal){
    if(e<i || b>j){
        return ;
    }
    if(b>=i && e<=j){
        tree[node].sum+= ((e-b+1)*newVal);
        tree[node].prop+=newVal;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,newVal);
    update(right,mid+1,e,i,j,newVal);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

int bin_search(int n,long long k){
    //cout<<n<<" "<<query(1,1,mx,6,6)<<endl;
    int lo=1,hi=n,ans=-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        long long srch=query(1,1,mx,mid,mid);
        //cout<<mid<<" "<<hi<<" "<<lo<<" "<<srch<<endl;
        if(srch>k){
            hi=mid-1;
        }
        else if(srch==k){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    //cout<<ans<<endl;
    return ans;
}

int main()
{
   int t,tc=0;
   scanf("%d",&t);
   while(t--){
        int n,q;
        long long k;
        scanf("%d %d",&n,&q);
        memset(arr,0,sizeof arr);
        for(int i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
        }
        init(1,1,mx);
        printf("Case %d:\n",++tc);
        while(q--){
            char ch;
            //cout<<q<<endl;
            getchar();
            scanf("%c %lld",&ch,&k);
           //printf("%c %lld\n",ch,k);
            if(ch=='c'){
                int ret=bin_search(n,k);
                //cout<<ret<<endl;
                if(ret!=-1){
                    printf("%d\n",arr[ret]);
                    update(1,1,mx,ret,n,-1);
                }
                else{
                    printf("none\n");
                }
            }
            else{
                n++;
                arr[n]=k;
                long long val=query(1,1,mx,n-1,n-1);
                //cout<<val<<" "<<query(1,1,mx,n,n)<<endl;
                update(1,1,mx,n,n,val+1-n);
                //cout<<val<<" "<<query(1,1,mx,n,n)<<endl;
            }
        }
   }
}
