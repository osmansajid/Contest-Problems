#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll low=0,high=n,mid,flag=0;
        if(n<=1){
            cout<<n<<endl;
        }
        else{
            while(low<=high){
                mid=(low+high)/2;
                if((mid+1)==2*n/mid){
                    flag=1;
                    break;
                }
                else if((mid+1)>2*n/mid){
                    high=mid-1;
                }
                else if((mid+1)<2*n/mid){
                    low=mid+1;
                }
            }
            if(flag==1){
                cout<<mid<<endl;
            }
            else{
                cout<<low-1<<endl;
            }
        }
     }
}
