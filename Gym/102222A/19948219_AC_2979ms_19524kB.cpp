#include<bits/stdc++.h>
using namespace std;
int n,p,q,m;
unsigned long long ans=0;
unsigned int SA,SB,SC;

unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
 }
 void gen(){
     unsigned int myst[5000010];
     unsigned int top=0;
     myst[0]=0;
     unsigned int tmp=0;
     scanf("%d%d%d%d%u%u%u", &n,&p,&q,&m,&SA,&SB,&SC);
     for(int i = 1; i <= n; i++){
         if(rng61() % (p + q) < p){
             unsigned int z=rng61() % m + 1;
             top++;
             myst[top]=max(z,myst[top-1]);
             ans^=((unsigned long long)i*(unsigned long long)myst[top]);
             //cout<<1<<" "<<tmp<<" "<<z<<endl;
             //cout<<z<<endl;
             //PUSH(z);

         }
         else{
            if(top<=0){
                //ans^=0;
            }
            else{
                top--;
                if(top==0){
                   // ans^=0;
                }
                else{
                    ans^=((unsigned long long)i*(unsigned long long)myst[top]);

                //cout<<0<<" "<<tmp<<endl;
                }
            }
         }
             //POP();
     }
}

int main()
{
    int tt,tc=0;
    scanf("%d",&tt);
    while(tt--){
        ans=0;
        gen();
        printf("Case #%d: %llu\n",++tc,ans);
        //cout<<"Case #"<<++tc<<": "<<ans<<endl;
    }
}
