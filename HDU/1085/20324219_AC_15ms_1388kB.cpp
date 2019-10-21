#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,z;
    while(scanf("%d %d %d",&x,&y,&z)){
        if(x==0 && y==0 & z==0) break;
        int ans=-1;
        int upto=x+(2*y)+(5*z);
        for(int i=1;i<=10000;i++){
            int f=0;
            if(i%2==0){
                int fv=min(z,i/5);
                if(fv%2!=0) fv--;
                int on=min(x,i/1);
                if(on%2!=0) on--;
                int tw=i-(on)-(5*fv);
                tw=tw/2;
                //cout<<fv<<" "<<on<<" "<<tw<<" "<<i<<endl;
                if(tw<=y){
                    continue;
                }
                else{
                    fv=min(z,i/5);
                    if(fv%2==0) fv--;
                    on=min(x,i/1);
                    if(on%2==0) on--;
                    if(fv<0 || on<0){
                        f=1;
                        ans=i;
                        break;
                    }
                    else{
                        tw=i-(on)-(5*fv);
                        tw=tw/2;
                        //cout<<fv<<" "<<on<<" "<<tw<<" "<<i<<endl;
                        if(tw>y){
                            f=1;
                            ans=i;
                            break;
                        }
                    }
                }
            }
            else{
                int fv=min(z,i/5);
                if(fv%2!=0) fv--;
                int on=min(x,i/1);
                if(on%2==0) on--;
                if(on<0){
                    fv=min(z,i/5);
                    if(fv%2==0) fv--;
                    on=min(x,i/1);
                    if(on%2!=0) on--;
                    if(fv<0){
                        f=1;
                        ans=i;
                        break;
                    }
                    else{
                        int tw=i-(on)-(5*fv);
                        tw=tw/2;
                       // cout<<fv<<" "<<on<<" "<<tw<<" "<<i<<endl;
                        if(tw>y){
                            f=1;
                            ans=i;
                            break;
                        }
                    }
                }
                else{
                    int tw=i-(on)-(5*fv);
                    tw=tw/2;
                    //cout<<fv<<" "<<on<<" "<<tw<<" "<<i<<endl;
                    if(tw<=y){
                        continue;
                    }
                    else{
                        fv=min(z,i/5);
                        if(fv%2==0) fv--;
                        on=min(x,i/1);
                        if(on%2!=0) on--;
                        if(fv<0){
                            f=1;
                            ans=i;
                            break;
                        }
                        else{
                            tw=i-(on)-(5*fv);
                            tw=tw/2;
                            //cout<<fv<<" "<<on<<" "<<tw<<" "<<i<<endl;
                            if(tw>y){
                                f=1;
                                ans=i;
                                break;
                            }
                        }
                    }
                }
            }
            if(f==1) break;
        }
        cout<<ans<<endl;
    }
}
