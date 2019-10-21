#include<bits/stdc++.h>
using namespace std;
#define mx 100010
long long arr[mx],tree[100010];

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
void update(int indx,int n, long long val)
{
    while (indx <= n){
        tree[indx] += val;
        indx += indx & (-indx);
    }
}



int main()
{
    int n,tc=0;
    int freq[mx];
    while(scanf("%d",&n)!=EOF){
        memset(tree,0,sizeof tree);
        memset(freq,0,sizeof freq);
        for(int i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
            update(i,n,arr[i]);
        }
        int next[n+2],prev[n+2];
        for(int i=0;i<=n;i++){
            next[i]=i+1;
        }
        //next[n]=mx-1;
        for(int i=1;i<=n+1;i++){
            prev[i]=i-1;
        }
        //prev[1]=0;
        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",++tc);
        while(q--){
            int ch,left,right;
            scanf("%d %d %d",&ch,&left,&right);
            if(left>right) swap(left,right);
            if(ch==1){
                printf("%lld\n",sum(right)-sum(left-1));
            }
            else{
                int cur=left;
                while(cur<=right){
                    //cout<<cur<<" ";
                    long long pval=arr[cur];
                    long long val=sqrt(arr[cur]);
                    arr[cur]=val;
                    update(cur,n,-pval+val);
                    if(val==1 && freq[cur]==0){
                        freq[cur]=1;
                        next[prev[cur]]=next[cur];
                        prev[next[cur]]=prev[cur];
                    }
                    //cout<<next[prev[next[3]]]<<endl;
                    //cout<<cur<<" "<<next[cur]<<" "<<prev[cur]<<" "<<next[prev[next[cur]]]<<endl;;
                    cur=next[prev[next[cur]]];
                }
                //cout<<endl;
            }
        }
    }
}

