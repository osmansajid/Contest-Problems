#include<bits/stdc++.h>
using namespace std;
long long dp[6];
int a[6];

long long call(int indx,int make)
{
    if(indx>=5){
        if(make==23){
            return 1;
        }
        else{
            return 0;
        }
    }
    long long res1=0,res2=0,res3=0;
    res1=call(indx+1,make+a[indx]);
    res2=call(indx+1,make-a[indx]);
    res3=call(indx+1,make*a[indx]);
    return res1|res2|res3;
}
int main()
{
    int p,q,r,s,t,cnt=0;
    //freopen("b.txt","w",stdout);
    while(scanf("%d %d %d %d %d",&p,&q,&r,&s,&t)==5){
        memset(a,0,sizeof a);
        int flag=0;
        if(p==0 && q==0 && r==0 && s==0 && t==0){
            break;
        }
        else{
            for(int i=0;i<5;i++){
                a[i]=p;
                for(int j=0;j<5;j++){
                    if(j!=i){
                        a[j]=q;
                        for(int k=0;k<5;k++){
                            if(k!=j && k!=i){
                                a[k]=r;
                                for(int l=0;l<5;l++){
                                    if(l!=i && l!=j && l!=k){
                                        a[l]=s;
                                        for(int m=0;m<5;m++){
                                            if(m!=i && m!=j && m!=k && m!=l){
                                                a[m]=t;
                                                //memset(dp,-1,sizeof dp);
                                                //if(a[0]==2 && a[1]==1 && a[2]==5 &&a[3]==4 && a[4]==3) cout<<"paisi"<<endl;
                                                //cout<<i<<j<<k<<l<<m<<endl;
                                                //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<endl;
                                                if(call(1,a[0])){
                                                    flag=1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(flag==0){
            cout<<"Impossible"<<endl;
        }
        else{
            cout<<"Possible"<<endl;
        }
    }
}
