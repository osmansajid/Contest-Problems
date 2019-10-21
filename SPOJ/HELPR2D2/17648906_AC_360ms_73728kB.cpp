#include <cstdio>
#include <algorithm>
#include <cstring>
#include<bits/stdc++.h>


using namespace std;

#define mx 1000010
int arr[mx];
int T, K, N, n;
char line[100];

//info is a structure to store the sums and update values(prop)
struct info{
    long long sum;
    int ind;
}tree[mx * 3];//3* of array size

info combine(info x,info y){
    info ret;
    if(x.sum>=y.sum){
        ret.sum=x.sum;
        ret.ind=x.ind;
    }
    else{
        ret.sum=y.sum;
        ret.ind=y.ind;
    }
    return ret;
}

//creates the tree
void init(int node,int b,int e){
    if(b==e){
        tree[node].sum=arr[b];
        tree[node].ind=b;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=combine(tree[left],tree[right]);
}

//gives ans to the cum sum in a given range of i to j... carry passes the updated value
info query(int node,int b,int e,long long val){
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    info res1;
    if(b==e) return tree[node];
    else if(tree[left].sum>=val){
        res1=query(left,b,mid,val);
    }
    else{
        res1=query(right,mid+1,e,val);
    }
    return res1;
}

//updates a number of an index
void update(int node, int b, int e, int i, long long newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node].sum = tree[node].sum-newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node]=combine(tree[Left],tree[Right]);
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {


		scanf( "%d %d\n", &K, &N );

		n=N;
		int ret1=-1;

		long long ans[n+1];

        for(int i=1;i<=n;i++){
            arr[i]=K;
            ans[i]=K;
        }

        init(1,1,n);

        long long a[n];

		int ships = 0, sum = 0;
		while ( N > 0 ) {

			scanf ("%[^\n]%*c", line);
			int cant, w;
			if ( sscanf( line, "b %d %d", &cant, &w ) != 2  ) {
			      sscanf( line, "%d", &w );
			      cant = 1;
			}


			N -= cant;
			//printf("s %d %d %d\n",cant,w,N);
			while ( cant-- ) {

                //cout<<"LL"<<endl;
				info res=query(1,1,n,w);
				ret1=max(ret1,res.ind);
                ans[res.ind]=ans[res.ind]-w;
            //cout<<w<<" "<<res.ind<<" "<<ans[res.ind]<<endl;
                update(1,1,n,res.ind,w);
			}

			//printf("%d %d %d\n",cant,w,N);
		}
        long long ret2=0;
        for(int i=1;i<=ret1;i++){
            ret2+=ans[i];
        }
        printf("%d %lld\n",ret1,ret2);
	}

	return 0;
}
