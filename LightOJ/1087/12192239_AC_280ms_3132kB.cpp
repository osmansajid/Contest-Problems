#include<bits/stdc++.h>
using namespace std;
#define mx 200010
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

int newpos(int pos){
    int low=1,high=mx-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(sum(mid)<pos){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}

int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        printf("Case %d:\n",++tc);
        memset(tree,0,sizeof tree);
        int n,m,k;
        scanf("%d %d",&n,&m);
        int a[200001];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            update(i,mx,1);
        }
        while(m--){
            char c;
            getchar();
            scanf("%c %d",&c,&k);
            if(c=='c'){
                int pos=newpos(k);
                if(pos>200000){
                    printf("none\n");
                }
                else{
                    printf("%d\n",a[pos]);
                    update(pos,mx,-1);
                }
            }
            else{
                int pos=newpos(sum(mx-5))+1;
                a[pos]=k;
                update(pos,mx,1);
            }
        }
    }
}
