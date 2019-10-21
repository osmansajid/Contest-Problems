#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin );
    freopen("output.txt","w",stdout);
    int n,flag=0,mx;
    scanf("%d",&n);
    char s[110];
    scanf("%s",&s);
    int a[110];
    int j=0,i;
    for(i=0;i<n;i++){
        if(s[i]=='1'){
            a[j]=i;
            j++;
        }
    }
    for(i=1;i<j;i++){
        if(i==1){
            mx=a[i]-a[i-1];
        }
        if((a[i]-a[i-1])!=mx){
            flag=1;
        }
    }
    if(flag==1){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
}
