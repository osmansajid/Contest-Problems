#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc=0;
   // freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        int a[n+10];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        printf("Case %d:\n",++tc);
        for(int i=0;i<q;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            int low=1,high=n,mid,mid2,flag=0;
            while(low<=high){
                mid=(low+high)/2;
                if(a[mid]==y){
                    flag=1;
                    break;
                }
                else if(a[mid]>y){
                    high=mid-1;
                }
                else if(a[mid]<y){
                    low=mid+1;
                }
            }
            if(y<a[mid]){
                mid--;
            }
            low=1,high=n,flag=0;
            while(low<=high){
                mid2=(low+high)/2;
                if(a[mid2]==x){
                    flag=1;
                    break;
                }
                else if(a[mid2]>x){
                    high=mid2-1;
                }
                else if(a[mid2]<x){
                    low=mid2+1;
                }
            }
            if(x>a[mid2]){
                mid2++;
            }
            printf("%d\n",(mid-mid2)+1);
        }
    }
    return 0;
}
