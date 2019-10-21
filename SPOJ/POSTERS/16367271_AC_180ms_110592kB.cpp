#include<bits/stdc++.h>
using namespace std;
#define mx 2000010

struct info{
    long long sum=0;
    long long prop=-1;
}tree[mx * 3];

void init(int node,int b,int e){
    if(b==e){
        tree[node].sum=0;
        tree[node].prop=-1;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].prop=-1;
}

void update(int node,int b,int e){
    if(b!=e){
        tree[2*node].prop=tree[node].prop;
        tree[(2*node)+1].prop=tree[node].prop;
    }
    tree[node].sum=tree[node].prop*(e-b+1);
    tree[node].prop=-1;
}

void update2(int node,int b,int e,int i,int j,long long newVal){
    if(tree[node].prop!=-1){
        update(node,b,e);
    }
    if(e<i || b>j){
        return ;
    }
    if(b>=i && e<=j){
        tree[node].sum= ((e-b+1)*newVal);
        if(b!=e){
            tree[2*node].prop=newVal;
            tree[(2*node)+1].prop=newVal;
        }
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update2(left,b,mid,i,j,newVal);
    update2(right,mid+1,e,i,j,newVal);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

long long query(int node,int b,int e,int i,int j,long long carry=0){
    if(tree[node].prop!=-1){
        update(node,b,e);
    }
    if(e<i || b>j){
        return 0;
    }
    if(b>=i && e<=j){
        return (tree[node].sum);
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    long long res1=query(left,b,mid,i,j,tree[node].prop);
    long long res2=query(right,mid+1,e,i,j,tree[node].prop);
    return res1+res2;
}


int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,low=INT_MAX,high=0,cnt=0,counter=0;
        init(1,1,mx);
        scanf("%d",&n);
        int frq[n+10];
        vector<int> comp;
        memset(frq,0,sizeof frq);
        map<int,int>mp;
        pair<int,int>q[n+10];
        for(int i=1;i<=n;i++){
            int l,r;
            scanf("%d %d",&l,&r);
            q[i]=make_pair(l,r);
            if(mp[l]==0){
                comp.push_back(l);
                mp[l]=1;
            }
            if(mp[r]==0){
                comp.push_back(r);
                mp[r]=1;
            }
            //cout<<"OK"<<endl;
        }
        sort(comp.begin(),comp.end());
        mp.clear();
        for(int i=0;i<comp.size();i++) mp[comp[i]]=i+1;
        for(int i=1;i<=n;i++){
            update2(1,1,mx,mp[q[i].first],mp[q[i].second],i+1);
            low=min(low,mp[q[i].first]);
            high=max(high,mp[q[i].second]);
        }
        for(int i=low;i<=high;i++){
            int x=query(1,1,mx,i,i,0);
            //cout<<x<<endl;
            if(frq[x]==0){
                cnt++;
                frq[x]=1;
            }
        }
        printf("%d\n",cnt);
    }
}



