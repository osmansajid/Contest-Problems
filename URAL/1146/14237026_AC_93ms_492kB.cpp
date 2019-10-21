#include<bits/stdc++.h>
using namespace std;
int n,cum[101][101],a[101][101];

int findm(int x,int y)
{
    int ret=-9999;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            //cout<<cum[x][y]<<" "<<cum[i-1][y]<<" "<<cum[x][j-1]<<" "<<cum[i-1][j-1]<<endl;
            ret=max(ret,cum[x][y]-cum[i-1][y]-cum[x][j-1]+cum[i-1][j-1]);
        }
    }
    //cout<<x<<" "<<y<<" "<<ret<<endl;
    return ret;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=i;k++){
                for(int l=1;l<=j;l++){
                    cum[i][j]+=a[k][l];
                }
            }
           // cout<<cum[i][j]<<" ";
        }
        //cout<<endl;
    }
    int ans=-INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans=max(findm(i,j),ans);
        }
    }
    cout<<ans<<endl;
}
