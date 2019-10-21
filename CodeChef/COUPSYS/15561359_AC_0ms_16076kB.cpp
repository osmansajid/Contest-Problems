#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,max1=-1,max2=-1,max3=-1,ans1,ans2,ans3;
        cin>>n;
        for(int i=0;i<n;i++){
            int c,l,d;
            cin>>c>>l>>d;
            if(l==1){
                if(max1<d){
                    max1=d;
                    ans1=c;
                }
                else if(max1==d){
                    //max1=d;
                    ans1=min(c,ans1);
                }
            }
            else if(l==2){
                if(max2<d){
                    max2=d;
                    ans2=c;
                }
                 else if(max2==d){
                    //max1=d;
                    ans2=min(c,ans2);
                }
            }
            else if(l==3){
                if(max3<d){
                    max3=d;
                    ans3=c;
                }
                else if(max3==d){
                    //max1=d;
                    ans3=min(c,ans3);
                }
            }
        }
        cout<<max1<<" "<<ans1<<endl;
        cout<<max2<<" "<<ans2<<endl;
        cout<<max3<<" "<<ans3<<endl;
    }
}
