#include<bits/stdc++.h>
using namespace std;

int tree[100010];

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
    cin>>t;
    while(t--){
        memset(tree,0,sizeof tree);
        int n,ans=0;
        cin>>n;
        string y[n],x[n];
        map<string,int> mp;
        //vector<pair<int,int> >pi;
        for(int i=0;i<n;i++){
            cin>>y[i];
            mp[y[i]]=i+1;
        }
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=n-1;i>=0;i--){
            ans+=sum(mp[x[i]]);
            //cout<<ans<<" "<<mp[x[i]]<<endl;
            update(mp[x[i]],n,1);
            //cout<<sum(1)<<" "<<sum(2)<<" "<<sum(3)<<" "<<sum(4)<<" "<<sum(5)<<endl;
        }
        cout<<ans<<endl;
    }
}
