#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
    cin>>t;
    while(t--){
        int n,counter=0,ans;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int k;
                k=a[i]+a[j];
                int low=j+1,high=n-1,mid;
                ans=0;
                while(low<=high){
                    mid=(low+high)/2;
                    if(a[mid]>=k){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                        ans=mid;
                    }
                }
                //cout<<i<<" "<<j<<" "<<mid<<endl;
                if(ans!=0){
                    counter+=ans-j;
                }
            }
        }
        cout<<"Case "<<++tc<<": "<<counter<<endl;
    }
}
