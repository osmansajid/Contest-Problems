#include<bits/stdc++.h>
using namespace std;
string board[8];
int markr[8],markc[8],mark[8][8];
vector<pair<int,int> >pos;
int bo[100][8][8],tmp[8][8],cnt=0;
int dp[8][256];

bool check(int x,int y){
    int tx,ty,f=0;
    tx=x,ty=y;
    for(int i=0;i<8;i++){
        if(tx-1>=0 && ty-1>=0){
            if(mark[tx-1][ty-1]){
                return true;
            }
            else{
                tx--;
                ty--;
            }
        }
        else break;
    }

    tx=x,ty=y;
    for(int i=0;i<8;i++){
        if(tx+1<=7 && ty-1>=0){
            if(mark[tx+1][ty-1]){
                return true;
            }
            else{
                tx++;
                ty--;
            }
        }
        else break;
    }
    tx=x,ty=y;
    for(int i=0;i<8;i++){
        if(tx-1>=0 && ty+1<=7){
            if(mark[tx-1][ty+1]){
                return true;
            }
            else{
                tx--;
                ty++;
            }
        }
        else break;
    }

    tx=x,ty=y;
    for(int i=0;i<8;i++){
        if(tx+1<=7 && ty+1<=7){
            if(mark[tx+1][ty+1]){
                return true;
            }
            else{
                tx++;
                ty++;
            }
        }
        else break;
    }
    return false;
}

int cal(pair<int,int>cur,int x,int y){
    if(cur.first==x && cur.second==y)return 0;
    if(cur.first==x) return 1;
    if(cur.second==y) return 1;
    if(abs(cur.first-x)==abs(cur.second-y)) return 1;
    return 2;
}

void precal(int indx,int tmp[8][8]){
    if(indx>=8){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                bo[cnt][i][j]=tmp[i][j];
            }
        }
        cnt++;
        //cout<<cnt<<endl;
        return;
    }
    for(int i=0;i<8;i++){
        if(!markc[i] && !check(indx,i)){
            tmp[indx][i]=1;
            markc[i]=1;
            mark[indx][i]=1;
            precal(indx+1,tmp);
            tmp[indx][i]=0;
            markc[i]=0;
            mark[indx][i]=0;
        }
    }
}

int call(int indx,int r,int c){
    if(indx==8){
        return 0;
    }
    //if(indx==7 && r==191 && cl==253)cout<<r<<" "<<cl<<" "<<dp[indx][r][cl]<<endl;
    if(dp[indx][r]!=-1) return dp[indx][r];
    int ret=10000000;
    int xx=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(bo[c][i][j]==1 && (r&(1<<xx))==0){
                int ans=call(indx+1,r|(1<<xx),c);
                ret=min(ret,cal(pos[indx],i,j)+ans);
                //if(indx==7 && r==191 && cl==253)cout<<r<<" "<<cl<<" "<<" "<<indx<<" "<<i<<" "<<j<<" "<<pos[indx].first<<" "<<pos[indx].second<<" "<<cal(pos[indx],i,j)<<" "<<ans<<endl;
            }
            if(bo[c][i][j]==1) xx++;
        }

    }
    //cout<<indx<<" "<<ret<<endl;
    return dp[indx][r]=ret;
}

int main()
{
    int t,tc=0;

    precal(0,tmp);
    scanf("%d",&t);
    getchar();
    while(t--){
        for(int i=0;i<8;i++){
            cin>>board[i];
            for(int j=0;j<8;j++){
                if(board[i][j]=='q')pos.push_back(make_pair(i,j));
            }
            getchar();
        }
        int ans=100000000;
//        memset(dp,-1,sizeof dp);

        for(int i=0;i<cnt;i++){
            memset(dp,-1,sizeof dp);
            ans=min(ans,call(0,0,i));
        }
        printf("Case %d: %d\n",++tc,ans);
        pos.clear();
    }
}
