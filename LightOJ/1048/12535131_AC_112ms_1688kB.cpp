#include<bits/stdc++.h>
using namespace std;
map<int,int>b;
int check(int n,int a[],int mid){
    int cp=0,cn=0;
    for(int i=0;i<=n;i++){
        if(a[i]>mid){
            return INT_MAX;
        }
        else if(cp+a[i]==mid){
            cn++;
            cp=0;
        }
        else if(cp+a[i]>mid){
            cn++;
            cp=a[i];
        }
        else{
            cp=cp+a[i];
        }
    }
    if(cp) cn++;
    return cn;
}

void print(int ans,int n,int a[],int k){
    int cp=0,cn=0;
    //cout<<n<<" "<<k<<endl;
    for(int i=0;i<=n;i++){
        if(cp+a[i]>ans){
            printf("%d\n",cp);
            cp=a[i];
            cn++;
        }
        else if(cp+a[i]==ans){
            printf("%d\n",cp+a[i]);
            cp=0;
            cn++;
        }
        else if(n-i==(k-cn)){
            printf("%d\n",cp+a[i]);
            cn++;
            cp=0;
        }
        else{
            cp=cp+a[i];
        }
    }
    if(cp) printf("%d\n",cp);
}

int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        int n,k,ans;
        cin>>n>>k;
        int a[n+10],c[n+10],hi=0,lo=1,mid;
        for(int i=0;i<=n;i++){
            cin>>a[i];
            hi+=a[i];
        }
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(check(n,a,mid)<=k+1){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        printf("Case %d: %d\n",++tc,ans);
        print(ans,n,a,k);
    }
}
